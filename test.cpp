#include <iostream>
#include "Dataset.hpp"
#include "ConfusionMatrix.hpp"
#include "LogisticRegression.hpp"
#include<vector>
int main(){
    std::string nomFichierTrain = "representation.train.csv";
    std::string nomFichierTrainLabel = "true_train_modif.csv";
    std::string nomFichierTest = "representation.testa.csv";
    std::string nomFichierTestLabel = "true_a_modif.csv";
    
    ConfusionMatrix matrice;

    Dataset trainSet(nomFichierTrain.c_str());
    Dataset trainLabel(nomFichierTrainLabel.c_str());
    Dataset testSet(nomFichierTest.c_str());
    Dataset testLabel(nomFichierTestLabel.c_str());
    int ntest = testSet.GetNbrSamples();
    int d = testSet.GetDim();
    LogisticRegression regresseur(&trainSet, &trainLabel);
    
    for(int i = 0; i<ntest; i++){
        std::vector<double> sample = testSet.GetInstance(i);
        int trueLabel = testLabel.GetInstance(i)[0];
        Eigen::VectorXd vecteur(d);
        for(int i = 0; i<d; i++){
            vecteur[i] = sample[i];
        }
        int predictedLabel = regresseur.Estimate(vecteur, 0.5);
        matrice.AddPrediction(trueLabel, predictedLabel);

    }
    matrice.PrintEvaluation();



}