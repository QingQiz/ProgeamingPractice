#include <iostream>
#include <fstream>
#include <cstring>
#include <mpi.h>
#include <algorithm>
#include <time.h>

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);
    std::ifstream in("in", std::ios::in);
    std::ofstream out("out", std::ios::out);
    MPI_Init(&argc, &argv);

    int size, rank, N, n;
    int *to_sort;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        std::cout << "Reading File `in`" << std::endl;
        in >> N;
    }
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    to_sort = new int[N];

    if (rank == 0) {
        for (int i = 0; i < N; ++i) {
            in >> to_sort[i];
        }
        std::cout << "Reading Done" << std::endl;
    }
    clock_t start_t = clock();
    MPI_Bcast(to_sort, N, MPI_INT, 0, MPI_COMM_WORLD);

    n = N / size + (rank < N % size);

    int begin = N / size * rank + std::min(rank, N % size);
    int end = begin + n;

    std::sort(to_sort + begin, to_sort + end);

    int *dev_item = new int[size - 1];
    int sel_size = std::min(size, n);
    int *selected = new int[sel_size];
    for (int i = begin, cnt = 0; i < end; i += n / (sel_size)) {
        selected[cnt++] = to_sort[i];
    }
    int *all_selected;
    int *all_sel_count = new int[size];
    int *all_sel_disp = new int[size];
    int all_sel_size;

    MPI_Gather(&sel_size, 1, MPI_INT,
               all_sel_count, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        all_sel_disp[0] = 0;
        for (int i = 1; i < size; ++i) {
            all_sel_disp[i] = all_sel_disp[i - 1] + all_sel_count[i - 1];
        }
        all_sel_size = all_sel_disp[size - 1] + all_sel_count[size - 1];
        all_selected = new int[all_sel_size];
    }
    MPI_Gatherv(selected, sel_size, MPI_INT,
            all_selected, all_sel_count, all_sel_disp, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        std::sort(all_selected, all_selected + all_sel_size);
        int step = all_sel_size / size;
        for (int i = step, cnt = 0; i < all_sel_size; i += step) {
            dev_item[cnt++] = all_selected[i];
        }
        delete []all_sel_disp;
        delete []all_sel_count;
        delete []all_selected;
    }
    MPI_Bcast(dev_item, size - 1, MPI_INT, 0, MPI_COMM_WORLD);

    int *sendCount = new int[size];
    int *sendDisp = new int[size];
    int *recvCount = new int[size];
    int *recvDisp = new int[size];
    memset(sendCount, 0, size * sizeof(int));
    for (int i = begin, cnt = 0; i < end; ++i) {
        if (cnt == size - 1) {
            sendCount[cnt] = end - i;
            break;
        }
        if (to_sort[i] <= dev_item[cnt]) {
            sendCount[cnt]++;
        } else {
            cnt++, i--;
        }
    }

    MPI_Alltoall(sendCount, 1, MPI_INT,
                 recvCount, 1, MPI_INT, MPI_COMM_WORLD);
    sendDisp[0] = begin;
    recvDisp[0] = 0;
    for (int i = 1; i < size; ++i) {
        sendDisp[i] = sendDisp[i - 1] + sendCount[i - 1];
        recvDisp[i] = recvDisp[i - 1] + recvCount[i - 1];
    }

    int recvSize = recvDisp[size - 1] + recvCount[size - 1];
    int *recvBuff = new int[recvSize];

    MPI_Alltoallv(to_sort, sendCount, sendDisp, MPI_INT,
                  recvBuff, recvCount, recvDisp, MPI_INT, MPI_COMM_WORLD);

    std::sort(recvBuff, recvBuff + recvSize);

    MPI_Gather(&recvSize, 1, MPI_INT, recvCount, 1, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = 1; i < size; ++i) {
        recvDisp[i] = recvDisp[i - 1] + recvCount[i - 1];
    }

    MPI_Gatherv(recvBuff, recvSize, MPI_INT,
                to_sort, recvCount, recvDisp, MPI_INT, 0, MPI_COMM_WORLD);

    clock_t end_t = clock();
    if (rank == 0) {
        std::cout << "Sorting Done: "
                  << double(end_t - start_t) / CLOCKS_PER_SEC
                  << std::endl;
        std::cout << "Writing File `out`" << std::endl;
        for (int i = 0; i < N; ++i) {
            out << to_sort[i] << '\n';
        }
        std::cout << "Writing done" << std::endl;
        std::cout << "IsSorted: "
                  << std::is_sorted(to_sort, to_sort + N) << std::endl;
    }

    delete []recvBuff;
    delete []recvDisp;
    delete []recvCount;
    delete []sendDisp;
    delete []sendCount;
    delete []dev_item;
    delete []to_sort;
    MPI_Finalize();
    return 0;
}
