#ifndef MODELINFO_HPP
#define MODELINFO_HPP

#include <iostream>

#include "../../solvers/asl.h"

namespace LPG {

//make life easier: these are defined in asl, but without the "m_pModel->" part
#ifdef conval
#undef conval
#endif
#ifdef jacval
#undef jacval
#endif
#define conval(x,r,ne)  (*((ASL*)m_pModel->asl)->p.Conval)((ASL*)m_pModel->asl,x,r,ne)
#define jacval(x,j,ne)  (*((ASL*)m_pModel->asl)->p.Jacval)((ASL*)m_pModel->asl,x,j,ne)
#define cgStart(P,Fv)   P->m_pModel->asl->i.Cgrad_[Fv->getId()]


    class ModelInfo {
        private:
            char *name;                 //model name
            FILE *nl;                   //.nl file
            double abound;              //artificial bound for unbounded variables
            double Infinity;            //largest number
            double negInfinity;         //most negative number


        public:
            ASL *asl;			//asl structure
            /* included in asl:
                    int n_var		//number of variables
                    int n_con 		//number of constraints
                    int nlc		//number of nonlinear constraints
                    double *LUrhs	//lower and upper bounds of constraints
                    double *LUv		//lower and upper bounds of variables
            */
            ModelInfo(char *stub);      //consttructor
            //~ModelInfo();
            //int get_n_var();
            //int get_n_con();
            void print() const;               //output basid data
            double getBound() const;          //return artificial bound value
            double getInfty() const;          //return infinity value
            double getNegInfty() const;       //return -infinity value
    };

};

#endif