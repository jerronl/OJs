#include<iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;
class BigInt{
    public:
    BigInt(const string& src):digits{0},negative(false){
        int cbase=1;
        for(auto c=src.rbegin();c!=src.rend();++c)
        switch (*c)
        {
        case '-':
            negative=digits.size()>1||!digits[0];
            return; 
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if(cbase>=weight
            /*||digits.back()*base>weight-c+'0'*/){
                digits.insert(digits.begin(), *c-'0');
                cbase=base;
            }else{
                digits.front()+=cbase*(*c-'0');
                cbase*=base;
            }
            break;
        // case '+':
        default:
            return;
        }
    }
    BigInt(long long src):digits(),negative(src<0){
        if(!src)
            digits.push_back(0);
        else {
            if(negative)
                src=-src;
            while(src){
                digits.insert(digits.begin(),src % weight);
                src/=weight;
            }
        }
    }
    operator const char*() const{
        string result=(negative && (digits.size()>1 ||digits[0]>0))?"-":"";
        bool leading=true;
        for(auto d:digits){
            auto sect=to_string(d);
            if(!leading)
                sect=string(sects-sect.size(),'0')+sect;
            result+=sect;
            leading=false;
        }
        return result.c_str();
    }
    BigInt operator +(const BigInt& rhs) const{
        int r=0;
        auto op1=&this->digits,op2=&rhs.digits;
        auto neg=negative;
        if(op1->size()<op2->size()){
            swap(op1,op2);
            neg=rhs.negative;
        }
        if(negative==rhs.negative){
            BigInt result(*op1,negative);
            auto& ndigits=result.digits;
            auto rite1=ndigits.rbegin();
            for(auto rite2=op2->rbegin();rite2!=op2->rend();++rite2,++rite1){
                *rite1+=(*rite2)+r;
                r=*rite1/weight;
                *rite1%=weight;
            }
            for(;r&&rite1!=ndigits.rend();++rite1){
                *rite1+=r;
                 r=*rite1/weight;
                *rite1%=weight;               
            }
            if(r)
                ndigits.insert(ndigits.begin(),r);
            return result;
        }else{
            auto rend1=op1->rend(), rend2=op2->rend();
            auto ite1=op1->begin(),ite2=op2->begin();
            if(op1->size()==op2->size()){
                for(;ite1!=op1->end()&&*ite1==*ite2;++ite1,++ite2,--rend1,--rend2);
                if(ite1==op1->end())
                    return 0;
                if(*ite1<*ite2){
                    swap(op1,op2);
                    ite1=ite2;
                    rend2=rend1;
                    neg=rhs.negative;
                }
            }
            BigInt result(vector<int>(ite1,op1->end()),neg);
            auto& ndigits=result.digits;
            auto rite1=ndigits.rbegin();
            for(auto rite2=op2->rbegin();rite2!=rend2;++rite2,++rite1)
                if(r=((*rite1-=(*rite2)+r)<0)?1:0)
                    *rite1+=weight;
            
            for(;r&&rite1!=ndigits.rend();++rite1)                
                if(r=((*rite1-=r)<0)?1:0)
                    *rite1+=weight;

            if(r)//wth
                ndigits.insert(ndigits.begin(),r);
            else for(auto ite=ndigits.begin();ite!=ndigits.end();++ite)
                if(*ite){
                    ndigits.erase(ndigits.begin(),ite);
                    break;
                }
            return result;
        }
    }
    private:
    BigInt(const vector<int>&digits={},bool negative=true)
        :digits(digits),negative(negative){}
    vector<int> digits;
    bool negative;
    static constexpr int weight=1e5,base=10,sects=5;
};
// ostream& operator <<(ostream& os,const BigInt& bi){
//     return os<<string(bi);
// }

int main() {
    vector<BigInt> bis{ {"123456789987654321"},   {"1234567899876"},
                        {"1234567899876"},        {"123456789987654321"},
                        {"123456789987654321"},   {"0"},
                        {"123456789987654321"},   {"-123456789987654321"},
                        {"-123456789987654321"},   {"123456789988654321"},
                        {"0"},                    {"123456789987654321"},
                        {"123456789987654321"},   {"-1234567899876"},
                        {"100000000000000000000000089987654321"},   {"-1234567899876"},
                        {"-1234567899876"},        {"-123456789987654321"},
                        {123456789987654321},   {-1234567899876},
                        {123456789987654321},   {0},
                        {1234567899876},        {"-123456789987654321"},
                        {"-123456789987654321"},  {"1234567899876"},
                        {"-1234567899876"},       {"123456789987654321"}
    };

    for(auto ite=bis.begin(),ite2=next(ite);ite!=bis.end();++++ite,++++ite2)
        cout<<*ite<<"+"<<*ite2<<"="<<*ite+*ite2<<'\n';
    return 0;
}