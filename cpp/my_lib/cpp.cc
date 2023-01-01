#ifndef __SUDOG41LIB__
#define __SUDOG41LIB__
inline int lowBitFristOne(int);
inline int lowBitFristZero(int);
#endif

inline int lowBitFristOne(int n){
    return (~n+1)&n;
}
inline int lowBitFristZero(int n){
    return ((~n-1)&n)+1;
}