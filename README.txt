L. Cerna &  M. Heinen
cernalue@gmail.com
marco@marco-heinen.de

Universidad de Guanajuato,
March 2018


This program reads an ASCII file
of N numbers, which must be provided in
ascending order, and determines
the number which is the closest-but-n
to a user-provided input.

The algorithm is a binary search of
O[ log(N) ]  in the best case, and of
O[ n ] int the worst case, if n >= N/2

 



Instructions:
=============

1.) Compiling and running:
--------------------------

cd src

make

cd ../bin/

./closest_but_n


2.) Cleaning up:
----------------

cd src

make clean
