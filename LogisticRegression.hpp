#include <Eigen/Dense>
#include <Eigen/Core>
#include "Dataset.hpp"


#ifndef LOGISTICREGRESSION_HPP
#define LOGISTICREGRESSION_HPP

class LogisticRegression {
private:
    
   Dataset* m_dataset;
   Dataset* m_label;
	Eigen::VectorXd* m_theta;
public:
   
	LogisticRegression(Dataset* dataset, Dataset* dataset2);
   
  ~LogisticRegression();
  
   
   double sigmoid(Eigen::VectorXd &theta, Eigen::VectorXd &x);
	void SetCoefficients(double tolerance);
  
	void ShowCoefficients();
  
	double Estimate( const Eigen::VectorXd & x , double threshold);



 Dataset* GetDataset();
};

#endif //LINEARREGRESSION_HPP
