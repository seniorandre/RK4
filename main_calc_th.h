#ifndef MAIN_CALC_TH_H
#define MAIN_CALC_TH_H

#include <QThread>

typedef struct sInputData{
    double epsilon;
    double e_up;
    double precision;
    int Nmax;
    double h0;
    //double k;
    //double f;
    //double m;
    //double u0;
    //double u_0;
    double x0;
    double xT;
    bool dif_step;
    std::vector<double> iv;
} InputData;

typedef struct sInputFunc{
    std::function<double(double, std::vector<double>)> f1;
    std::function<double(double, std::vector<double>)> f2;
} InputFunc;

class MainCalcTh : public QThread
{
Q_OBJECT
private:
    InputData *inD;
    InputFunc *inF;

    std::pair< std::pair<std::vector<double>, std::vector<std::vector<double>>>,
        std::pair<std::vector<std::pair<int,std::string>>,std::vector<std::pair<int,std::string>>>> answer;
public:   
    MainCalcTh(){}
    void setInputData(InputData *inData, InputFunc *inFunc);

    std::pair< std::pair<std::vector<double>, std::vector<std::vector<double>>>,
        std::pair<std::vector<std::pair<int,std::string>>,std::vector<std::pair<int,std::string>>>> &get_answer(void);
protected:
    void run();
signals:
     void resultReady(void);
};

#endif // MAIN_CALC_TH_H
