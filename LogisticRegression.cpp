#include "LogisticRegression.hpp"
#include "Dataset.hpp"
#include<iostream>
#include<cassert>
#include<vector>



LogisticRegression::LogisticRegression( Dataset* dataset, Dataset* dataset2) 
 {
	
    m_dataset = dataset;
    m_label = dataset2;
    
	SetCoefficients(0.001);
}

LogisticRegression::~LogisticRegression() {
  delete m_theta;
  
}

double LogisticRegression::sigmoid(Eigen::VectorXd &theta, Eigen::VectorXd &x){
    return 1./(1.+ exp(-1.*theta.dot(x)));
}

void LogisticRegression::SetCoefficients(double tolerance) {
	int n = m_dataset->GetNbrSamples();
	int d = m_dataset->GetDim();
    double alpha = 0.1;
    Eigen::VectorXd theta = Eigen::VectorXd::Zero(d+1);
	Eigen::VectorXd temporaire(d+1);
	bool fini = false;

	while(!fini){
    temporaire[0] = 1;

    for(int w = 0; w<n;w++){
    
        std::vector<double> vecteur = m_dataset->GetInstance(w);
        for(int i = 0; i<d; i++){
            
            temporaire[i+1] = vecteur[i];
        
        }
		Eigen::VectorXd updateVector = (m_label->GetInstance(w)[0]- sigmoid(theta,temporaire))*temporaire;
		double e = updateVector.lpNorm<1>();
        theta = theta + alpha*updateVector;
		if(e < tolerance){
			fini = true;
		}
    	}
	}
	m_theta = new Eigen::VectorXd(d+1);
	*m_theta = theta;
}

void LogisticRegression::ShowCoefficients() {
	if (!m_theta) {
		std::cout<<"Coefficients have not been allocated."<<std::endl;
		return;
	}
	
	if (m_theta->size() != m_dataset->GetDim()+1) {  
		std::cout<< "Warning, unexpected size of coefficients vector: " << m_theta->size() << std::endl;
	}
	
	std::cout<< "beta = (";
	for (int i=0; i<m_theta->size(); i++) {
		std::cout<< " " << (*m_theta)[i];
	}
	std::cout << " )"<<std::endl;
}


double LogisticRegression::Estimate( const Eigen::VectorXd & x , double threshold) {

	Eigen::VectorXd y(x.size()+1);
	y(0) = 1;
	for(int i = 0; i< x.size(); i++){
		y(i+1) = x(i);
	}
    double sig = sigmoid(*m_theta,y);
    if (sig > threshold){
        return 1;
    }
    else{
        return 0;
    }
}



Dataset* LogisticRegression::GetDataset() {
    return m_dataset;
}