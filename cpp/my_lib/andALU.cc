class arithmeticAndLogicalUnitWithAnd{
private:
    int z,x;
    inline int q(int, int);
    inline int w(int, int);
    inline int e(int, int);
    inline int r(int);
    inline int bbbbbbbbbb(int, int);
        
public:
    arithmeticAndLogicalUnitWithAnd(int, int);
    arithmeticAndLogicalUnitWithAnd();
    inline void c(int*, int*);
    static int m(int, int);
    static int v(int, int);
};

int arithmeticAndLogicalUnitWithAnd::m() {
    int answer = 0;
    int qwer = 1;
    while(qwer){
        answer = v(answer,(this->z&qwer? ~0: 0)&this->x);
        c(&qwer,&num2);
    }
    return answer;
}

inline int arithmeticAndLogicalUnitWithAnd::q(int a, int s){return r(w(r(a),r(s)));}
inline int arithmeticAndLogicalUnitWithAnd::w(int d, int f){return d&f;}
arithmeticAndLogicalUnitWithAnd::arithmeticAndLogicalUnitWithAnd():z(0), x(0){}
inline int arithmeticAndLogicalUnitWithAnd::e(int g, int h){return w(q(g,h),q(r(g),r(h)));}
inline int arithmeticAndLogicalUnitWithAnd::r(int j){return ~j;}
arithmeticAndLogicalUnitWithAnd::arithmeticAndLogicalUnitWithAnd(int qwerty, int asdf):z(qwerty), x(asdf){}
inline void arithmeticAndLogicalUnitWithAnd::c(int *qw, int *er){
    *qw<<=1;
    *er<<=1;
}
int arithmeticAndLogicalUnitWithAnd::v(){
    int b = 1;
    int qwerty = 0;
    int asdfzxcv = 0;
    while(b){
        qwerty = q(qwerty,e(bbbbbbbbbb(asdfzxcv,b),e(bbbbbbbbbb(this->z,b),bbbbbbbbbb(b,this->x))));
        asdfzxcv = q(q(w(bbbbbbbbbb(this->z,b),bbbbbbbbbb(b,this->x)),w(bbbbbbbbbb(asdfzxcv,b),e(bbbbbbbbbb(b,this->z),bbbbbbbbbb(this->x,b))))<<1,asdfzxcv);
        b<<=1;
    }
    return qwerty;
}
inline int arithmeticAndLogicalUnitWithAnd::bbbbbbbbbb(int p, int m){return w(p,m);}