#ifndef MOR_EX_SOMA_H_
#define MOR_EX_SOMA_H_

#include "biodynamo.h"
#include "biology-modules.h"
#include "core/substance_initializers.h"
#include "my-neurite.h"
#include "neuroscience/neuroscience.h"
#include <iostream>
#include <fstream>
#include "neurite_element.h"


/*
This function take the soma from the simulation and measures it's diameter, position and simulation pointer.

I am currently trying to figure out how I can get the neurite that is extended from the soma
*/


namespace bdm {

    // Function to record the morphology of soma
    //argument :  name of the file to be created
    template <typename TSimulation = Simulation<>>
    void WriteSoma(std::string file_name ) {
    auto* sim = TSimulation::GetActive();
    auto* rm = sim->GetResourceManager();
    auto soma = rm->template Get<experimental::neuroscience::NeuronSoma>();

    int n = rm->GetNumSimObjects();
    std::cout<< "Number of Simulation object :"<< n<< std::endl;


    ofstream Neural_Network_Morphology;
    Neural_Network_Morphology.open(file_name,ios::out | ios::app);

            // recording the diameter, position and simulation objct pointer
            auto diameter = soma->GetDiameter();
            auto position = soma->GetPosition();
            auto so_ptr = soma->GetSoPtr();

           //GetDaughters on soma 
            auto& daughters = soma->GetDaughters();
            auto&& daughter_dia = daughters[0]->GetDiameter();
            auto&& daughter_pos = daughters[0]->GetPosition();
            auto&& daughter_so_ptr = daughters[0]->GetSoPtr();
            auto&& mother = daughters[0]->GetDaughterLeft();
            cout<<"Mother"<<mother->GetDiameter()<<endl;
            
           
            // writing to console and the file
            cout<<"S.No:  "<<"  Diameter  "<<diameter<<"  Position  "<<position[0]<<" "<<position[1]<<" "<<position[2]<<"  SO Ptr  "<< so_ptr  <<endl;
            Neural_Network_Morphology<<"S.No: "<<" "<<"  Diameter: "<<diameter<<"  Position: "<<position[0]<<" "<<position[1]<<" "<<position[2]<<endl;

            // daughter morphologies
            cout<<"**"<< "  daughter_dia   "<<daughter_dia <<"  daughter_pos  "<<daughter_pos[0]<<"  daughter_so_ptr  "<<daughter_so_ptr<<endl;
   
    
       
}

} //namespace bdm 

#endif  // MOR_EX_SOAM_H_

