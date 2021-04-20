# CS204_hw5
Operator overloading for virtual wallet application



In this homework, you are asked to implement a class for virtual wallet and overload some operators for it. The details of these operators will be given below. Our focus in this homework is on the class design and implementation. The usage of this class in the main function will be given to you.


You will use a struct called money to model a single monetary item. In this struct, there will be a data member to store name of the currency (of type string, in case sensitive manner) and another data member to store the amount (of type double). If you want, you can write constructor(s) for this struct, but not needed for the main program. However, you will not write any member functions for this struct (well, we have not learned how to write member functions for structs in anyway).
The virtual wallet will be implemented as a class. In the wallet class, there should be two private data members: (i) the currencies and their amounts in the wallet as a dynamic array of money struct (i.e. money pointer); (ii) the size of this dynamic array, i.e. the number of distinct currencies stored in the wallet object.
The class should be designed and implemented in such a way that (i) a currency in the array must always have a positive amount, and (ii) a particular currency should exist in at most one item in the array.
