; LBYARCH x86 - to - C Interface Programming Project
;       > ASPECTO, Don Laude
;       > DE RAMOS, Ghrazielle Rei A.

section .text
bits 64
default rel

global zoperation1

zoperation1:
   mulsd xmm0, xmm1
   addsd xmm0, xmm2

   ret