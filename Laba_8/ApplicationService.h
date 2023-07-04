#pragma once

void getAllInfo(double& A, double& B, int& Var, int& N, bool& retflag);

double func6Var(double x);

double func9Var(double x);




bool isRootExists(double A, double B, double(*function_var)(double x));

double bisectionMethod(double A, double B, double(*function_var)(double x), double epsilon, int& k1);


double simpleIterationMethod(double A, double B, double(*function_var)(double x), double epsilon, int& k2);