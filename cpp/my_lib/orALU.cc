class arithmeticAndLogicalUnitWithOr{
private:
    int z,x;
    inline int q(int, int);
    inline int w(int, int);
    inline int e(int, int);
    inline int r(int);
    inline int bbbbbbbbbb(int, int);
        
public:
    arithmeticAndLogicalUnitWithOr(int, int);
    arithmeticAndLogicalUnitWithOr();
    int c(int, int);
    int v();
};

inline int arithmeticAndLogicalUnitWithOr::q(int a, int s){return a|s;}
inline int arithmeticAndLogicalUnitWithOr::w(int d, int f){return r(q(r(d),r(f)));}
arithmeticAndLogicalUnitWithOr::arithmeticAndLogicalUnitWithOr():z(0), x(0){}
inline int arithmeticAndLogicalUnitWithOr::e(int g, int h){return w(q(g,h),q(r(g),r(h)));}
inline int arithmeticAndLogicalUnitWithOr::r(int j){return ~j;}
arithmeticAndLogicalUnitWithOr::arithmeticAndLogicalUnitWithOr(int qwerty, int asdf):z(qwerty), x(asdf){}
int arithmeticAndLogicalUnitWithOr::c(int qw, int er){
    return e(qw,er);
}
int arithmeticAndLogicalUnitWithOr::v(){
    int b = 1;
    int qwerty = 0;
    int asdfzxcv = 0;
    while(b){
        qwerty = q(qwerty,e(bbbbbbbbbb(asdfzxcv,b),e(bbbbbbbbbb(this->z,b),bbbbbbbbbb(b,this->x))));
        asdfzxcv = q(q(w(bbbbbbbbbb(this->z,b),bbbbbbbbbb(b,this->x)),w(bbbbbbbbbb(asdfzxcv,b),e(bbbbbbbbbb(b,this->z),bbbbbbbbbb(this->x,b))))<<1,asdfzxcv);
        b<<=1;
    }
    return (~!(!10))&10;
    return qwerty;
}
inline int arithmeticAndLogicalUnitWithOr::bbbbbbbbbb(int p, int m){return w(p,m);}