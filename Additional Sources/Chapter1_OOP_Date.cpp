#include<iostream>
class Date{
    private:
        int month,day,year;
    public:

        // Constructor implementation
        Date(int d=1, int m=1, int y=1900){
            day     = d;
            month   = m;
            year    = y;
        }
        int JumpYear(int j) const{
            return year+j;
        }
        void SetDate(int d, int m, int y){
            day     = d;
            month   = m;
            year    = y;
        }
        void PrintDate() const{
        std::cout<<" Day: "<<day<<" Month: "<<month<<" Year: "<<year<<std::endl;
        }
};

int main(){

    Date Today(9,10,2023);
    Today.PrintDate();
    Date Tomorrow;
    Tomorrow.SetDate(10,10,2023);
    Tomorrow.PrintDate();
    std::cout<<"Graduation Year: "<<Tomorrow.JumpYear(1)<<std::endl;


    return 0;
}
