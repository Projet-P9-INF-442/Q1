#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#ifndef DATASET_HPP
#define DATASET_HPP

class Dataset {
    public:
      
        Dataset(const char* file);
       
        ~Dataset();
        
      
        void Show(bool verbose);
      
    	std::vector<double> GetInstance(int i);
       
    	int GetNbrSamples();
       
    	int GetDim();

    private:
       
		int m_dim;
       
		int m_nsamples;
     
        std::vector<std::vector<double> > m_instances;
};
#endif //DATASET_HPP
