#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex{
    public:
        complex(double r=0, double i=0 ): re(r),im(i){ }
        complex& operator -=(const complex&); //只写一个成员操作符重载
        double real() const { return re;}
        double imag() const{return im;}
    private:
        double re,im;
        friend complex& __doami(complex*,const complex& ); //复数减法 
};


// 示例：复数减法 、成员操作符重载-=
inline complex& __doami(complex* it, const complex& r){
    it->re-= r.re;
    it->im-=r.im;
    return *it;
}

inline complex& complex::operator-=(const complex& r){
    return __doami(this,r);
}

//示例：复数（全局操作符重载-）
inline complex operator- (const complex& x, const complex& y){
    return complex(x.real()-y.real(), x.imag()-y.imag());
}

inline complex operator-(const complex& x, double y ){
    return complex(x.real()-y, x.imag());
}


#endif
