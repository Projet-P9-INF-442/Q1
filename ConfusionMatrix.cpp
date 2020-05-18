#include "ConfusionMatrix.hpp"
#include <iostream>

using namespace std;

ConfusionMatrix::ConfusionMatrix() {
    
    
    m_confusion_matrix[0][0]= 0;
    m_confusion_matrix[0][1]= 0;
    m_confusion_matrix[1][0]= 0;
    m_confusion_matrix[1][1]= 0;
}

ConfusionMatrix::~ConfusionMatrix() {
   
}

void ConfusionMatrix::AddPrediction(int true_label, int predicted_label) {
   
    m_confusion_matrix[true_label][predicted_label]++;
}

void ConfusionMatrix::PrintEvaluation() const{
    
    cout <<"\t\tPredicted\n";
    cout <<"\t\t0\t1\n";
    cout <<"Actual\t0\t"
        <<GetTN() <<"\t"
        <<GetFP() <<endl;
    cout <<"\t1\t"
        <<GetFN() <<"\t"
        <<GetTP() <<endl <<endl;
    
    cout <<"Error rate\t\t"
        <<error_rate() <<endl;
    cout <<"False alarm rate\t"
        <<false_alarm_rate() <<endl;
    cout <<"Detection rate\t\t"
        <<detection_rate() <<endl;
    cout <<"F-score\t\t\t"
        <<f_score() <<endl;
    cout <<"Precision\t\t"
        <<precision() <<endl;
}

int ConfusionMatrix::GetTP() const {
    return m_confusion_matrix[1][1];
}

int ConfusionMatrix::GetTN() const {
   return m_confusion_matrix[0][0];
}

int ConfusionMatrix::GetFP() const {
    return m_confusion_matrix[0][1];
}

int ConfusionMatrix::GetFN() const {
   return m_confusion_matrix[1][0];
}

double ConfusionMatrix::f_score() const {
   
    double preci = precision();
    double rec = detection_rate();
    return (2*preci*rec)/(preci+rec);
}

double ConfusionMatrix::precision() const {
   
    double resultat = (double)m_confusion_matrix[1][1]/ (m_confusion_matrix[1][1]+m_confusion_matrix[0][1]);
    return resultat;
}

double ConfusionMatrix::error_rate() const {
    int total = m_confusion_matrix[0][0]+m_confusion_matrix[0][1]+m_confusion_matrix[1][0]+m_confusion_matrix[1][1];
    int erreurs = m_confusion_matrix[1][0] + m_confusion_matrix[0][1];
    return (double)erreurs /total;
}

double ConfusionMatrix::detection_rate() const {

    double resultat = (double)m_confusion_matrix[1][1] / (double)(m_confusion_matrix[1][1]+m_confusion_matrix[1][0]);
    return resultat;
}

double ConfusionMatrix::false_alarm_rate() const {
   
    double resultat = (double)m_confusion_matrix[0][1]/ (double)(m_confusion_matrix[0][1]+m_confusion_matrix[0][0]);
    return resultat;
}
