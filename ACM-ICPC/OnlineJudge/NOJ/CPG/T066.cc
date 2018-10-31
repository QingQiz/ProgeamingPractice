#include <stdio.h>
struct complex {
  double Re, Im;
};
int main() {
  struct complex z1, z2;
  scanf("%lf%lf", &z1.Re, &z1.Im);
  scanf("%lf%lf", &z2.Re, &z2.Im);
  printf("(%.2lf%+.2lfi)+(%.2lf%+.2lfi)=(%.2lf%+.2lfi)\n", z1.Re, z1.Im, z2.Re,
         z2.Im, z1.Re + z2.Re, z1.Im + z2.Im);
  printf("(%.2lf%+.2lfi)-(%.2lf%+.2lfi)=(%.2lf%+.2lfi)\n", z1.Re, z1.Im, z2.Re,
         z2.Im, z1.Re - z2.Re, z1.Im - z2.Im);
  printf("(%.2lf%+.2lfi)*(%.2lf%+.2lfi)=(%.2lf%+.2lfi)\n", z1.Re, z1.Im, z2.Re,
         z2.Im, z1.Re * z2.Re - z1.Im * z2.Im, z1.Re * z2.Im + z2.Re * z1.Im);
  printf("(%.2lf%+.2lfi)/(%.2lf%+.2lfi)=(%.2lf%+.2lfi)", z1.Re, z1.Im, z2.Re,
         z2.Im,
         (z1.Re * z2.Re + z1.Im * z2.Im) / (z2.Re * z2.Re + z2.Im * z2.Im),
         (z1.Im * z2.Re - z1.Re * z2.Im) / (z2.Re * z2.Re + z2.Im * z2.Im));
  return 0;
}