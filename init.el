;;; init.el --- Spacemacs Initialization File
;;
;; Copyright (c) 2012-2017 Sylvain Benner & Contributors
;;
;; Author: Sylvain Benner <sylvain.benner@gmail.com>
;; URL: https://github.com/syl20bnr/spacemacs
;;
;; This file is not part of GNU Emacs.
;;
;;; License: GPLv3

;; Without this comment emacs25 adds (package-initialize) here
;; (package-initialize)

;; Increase gc-cons-threshold, depending on your system you may set it back to a
;; lower value in your dotfile (function `dotspacemacs/user-config')
(setq gc-cons-threshold 100000000)

(defconst spacemacs-version         "0.200.13" "Spacemacs version.")
(defconst spacemacs-emacs-min-version   "24.4" "Minimal version of Emacs.")

(if (not (version<= spacemacs-emacs-min-version emacs-version))
    (error (concat "Your version of Emacs (%s) is too old. "
                   "Spacemacs requires Emacs version %s or above.")
           emacs-version spacemacs-emacs-min-version)
  (load-file (concat (file-name-directory load-file-name)
                     "core/core-load-paths.el"))
  (require 'core-spacemacs)
  (spacemacs/init)
  (configuration-layer/sync)
  (spacemacs-buffer/display-startup-note)
  (spacemacs/setup-startup-hook)
  (require 'server)
  (unless (server-running-p) (server-start)))




(setq default-tab-width 4)
(setq-default indent-tabs-mode nil)
(setq c-default-style "linux")
(setq c-basic-offset 4)



(global-set-key (kbd "<f5>") 'smart-compile)
(defun smart-compile()
  (interactive)
  ;; 查找 Makefile
  (let ((candidate-make-file-name '("makefile" "Makefile" "GNUmakefile"))
        (command nil))
    (if (not (null
               (find t candidate-make-file-name :key
                     '(lambda (f) (file-readable-p f)))))
      (setq command "make -k ")
      ;; 没有找到 Makefile ，查看当前 mode 是否是已知的可编译的模式
      (if (null (buffer-file-name (current-buffer)))
        (message "Buffer not attached to a file, won't compile!")
        (if (eq major-mode 'c-mode)
          (setq command
                (concat "gcc -Wall -o "
                        (file-name-sans-extension
                          (file-name-nondirectory buffer-file-name))
                        " "
                        (file-name-nondirectory buffer-file-name)
                        " -g -lm "))
          (if (eq major-mode 'c++-mode)
            (setq command
                  (concat "g++ -Wall -o "
                          (file-name-sans-extension
                            (file-name-nondirectory buffer-file-name))
                          " "
                          (file-name-nondirectory buffer-file-name)
                          " -g -lm "))
            (message "Unknow mode, won't compile!")))))
    (if (not (null command))
      (let ((command (read-from-minibuffer "Compile command: " command)))
        (compile command)))))
