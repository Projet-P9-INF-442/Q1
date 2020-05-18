
#ifndef CONFUSIONMATRIX_HPP
#define CONFUSIONMATRIX_HPP


class ConfusionMatrix {

    public:
        
        ConfusionMatrix();
      
        ~ConfusionMatrix();

      
        void AddPrediction(int true_label, int predicted_label);

      
        void PrintEvaluation() const;
        
      
        int GetTP() const;
    
       
        int GetTN() const;
    
       
        int GetFP() const;
    
       
        int GetFN() const;
    
       
        double f_score() const;
    
       
        double precision() const;
    
        double error_rate() const;
    
       
        double detection_rate() const;
    
       
        double false_alarm_rate() const;

    private:
      
        int m_confusion_matrix[2][2];
};

#endif    
