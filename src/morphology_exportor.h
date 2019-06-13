#ifndef MORPHOLOGY_EXPORTER_H_
#define MORPHOLOGY_EXPORTER_H_

#include "biodynamo.h"
#include "biology-modules.h"
#include "core/substance_initializers.h"
#include "my-neurite.h"
#include "neuroscience/neuroscience.h"
#include <iostream>
#include <fstream>
#include "neurite_element.h"


namespace bdm {

    // Function to write the morphology of neurite elements
    // Argument:  name of the file to be created
    template <typename TSimulation = Simulation<>>
    void WriteMorphology(std::string file_name ) {
    auto* sim = TSimulation::GetActive();
    auto* rm = sim->GetResourceManager();
  //  auto my_neurites = rm->template Get<MyNeurite>();
    
    int n = rm->GetNumSimObjects();
    
    //auto ptr = rm->GetSoPtr();
    
    std::cout<< "Number of Simulation object :"<< n<< std::endl;

    ofstream Neural_Network_Morphology_neurite;
   	Neural_Network_Morphology_neurite.open(file_name,ios::out | ios::app);

    //Get the position and diameter
    rm->ApplyOnAllElements([&](auto&& so, const SoHandle&) {
    auto& pos = so.GetPosition();
    auto type = so.GetDiameter();
    auto ne_soptr = so.GetSoPtr();

    //writing on the console and the file
   // cout<<"Position:  "<<pos[0]<<"  "<<pos[1]<<"  "<<pos[2]<<"   Diameter:  "<<type<<"  "<<"  SO PTR:   "<< ne_soptr <<endl;
	Neural_Network_Morphology_neurite<<" "<<"  Diameter: "<<type<<"  Position: "<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<"  "<<"  SO PTR:   "<< ne_soptr <<endl;
    
  });
            

/*
    
        for (int i = 0; i < n; i++){
            auto diameter = (*my_neurites_2)[i].GetDiameter();
            auto position = (*my_neurites_2)[i].GetPosition();
            auto so_ptr = (*my_neurites_2)[i].GetSoPtr();
            
            cout<<"S.No:  "<<i<<"  Diameter  "<<diameter<<"  Position  "<<position[0]<<" "<<position[1]<<" "<<position[2]<<"  SO Ptr  "<< so_ptr  <<endl;

            auto SOMA_PTR = (*my_neurites)[i].GetMySoma();
            cout<<"SOMA PTR = "<< SOMA_PTR<<endl;
            auto so_ptr_ele = (*my_neurites)[i].GetNeuriteElementSoPtr();
            cout<<"Neurite element pointer: "<< so_ptr <<endl;
            
            Neural_Network_Morphology<<"S.No: "<<i<<" "<<"  Diameter: "<<diameter<<"  Position: "<<position[0]<<" "<<position[1]<<" "<<position[2]<<endl;
        }

        
        
   

    auto mother = (my_neurites)->GetMother()->GetDiameter();
        cout<<"mother diameter = "<< mother<<endl;
        auto daughter_l = (my_neurites)->GetMother() ;
        auto daughter_dia = (daughter_l)->GetDiameter();
        cout<<"daughter_diameter: "<< daughter_dia <<endl;

       // auto  daughter_l_1 = daughter_l->GetDaughterLeft() ;
        //auto daughter_l_1_dia = daughter_l_1->GetDiameter();

        //auto  daughter_l_2 = daughter_l_1->GetDaughterLeft() ;
       // auto daughter_l_2_dia = daughter_l_2->GetDiameter();

        //cout<<"daughter dia"<<daughter_dia<<daughter_l_1_dia<<daughter_l_2_dia<<endl;
      

        auto neurite_type = (*my_neurites_2)[i].GetNeuriteType();
            cout<<"Neurite type"<< neurite_type << endl;


        auto so_ptr_D_L = daughter_l.GetSoPtr();
        cout<<"daughter left : "<<so_ptr_D_L<<endl;
        auto daughter_r = (*my_neurites)[1].GetDaughterRight() ;
        auto so_ptr_D_R = daughter_r.GetSoPtr();
        cout<<"daughter right : "<<so_ptr_D_R<<endl;


        //auto daughter_diameter = daughter_l.GetDiameter();
        //auto daughter_position = daughter_l.GetPosition();

        //cout<<"Daughter diameter: "<<daughter_diameter<<endl;
        */
        
}

} //namespace bdm 

#endif  // VALIDATION_CRITERION_H_

