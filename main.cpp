#include"gestion.h"
#include<ctime>



int main(int argc, char** argv) {

int n,c,t_s=0,j=0,c1,v;
string cd;


cout<<"\t Bonjour, Bienvenue dans mon system du gestion d'un hopital !! \nMerci d'entrer le nombre max des services a traite "<<endl;
cin>>n;
service* tab= new service[n];
do{
v=0;
c=0;
c1=0;
c=menu();

switch(c)
{
	case 1:{
		system("cls");
		service s;
		s=creation_ser();
		if(ajout_ser(tab,t_s,s))
		cout<<"**** Service ajoute avec succes"<<endl;
		else
		cout<<"**** Erreur"<<endl;
		break;
	}
	
	case 2:{
		system("cls");
		cout<<"Entrer le code du service a verfie"<<endl;
		cin>>cd;
		if(verf_serv(tab,t_s,cd))
		cout<<"**** Le service existe dans le system"<<endl;
		else
		cout<<"**** Service introuvable"<<endl;
		break;
	}
	
	case 3:{
		system("cls");
		cout<<"Entrer le code du service a supprime"<<endl;
		cin>>cd;
		if(supp_ser(tab,t_s,cd))
		cout<<"**** Le service est supprime avec succes"<<endl;	
		break;
	}
	
	case 4:{
		system("cls");
		aff_tab_ser(tab,t_s);
		break;
	}
	
	case 5:{
		system("cls");
		service* t1 = new service[n];
		t1=serv_anc(tab,t_s,j);
	    cout<<"\t\t Les services avec 10 ans d'experience :"<<endl;
		aff_tab_ser(t1,j);
		delete []t1;
		break;
	}
	
	case 6:{
		system("cls");
		cout<<"Entrer le code du service a traite"<<endl;
		cin>>cd;
		j=0;
		if(verf_serv_ind(tab,t_s,j,cd))
		{
do{	v=0;
		c1=menu1();
				
		switch(c1)
		  {
		  	case 1:{
		              system("cls");
		              cout<<"Entrer l'id de l'infirmier a verifie"<<endl;
		              cin>>cd;
					  if(tab[j].verif_inf(cd))
					  cout<<"**** L'infirmier existe dans le service"<<endl;
					  else
		              cout<<"**** L'infirmier n'existe pas dans le service"<<endl;  		
		  		
				break;
			  }
			  
			case 2:{
		              system("cls");
					  cout<<"Entrer les information du L'infirmier a ajoute :"<<endl;
					  infirmier in;
					  in=creation_infi();
					  if(tab[j].ajout_inf(in))
					  cout<<"**** L'infirmier est ajoute dans le service avec succes"<<endl;
					  
					  				       
				break;
			}
			
			case 3:{
		              system("cls");
					  string ncd;		              
					  cout<<"Entrer le nouveau nom du service"<<endl;
					  cin>>ncd;
					  tab[j].set_nom(ncd);
					  cout<<"**** Le nom du service est modifie avec succes"<<endl;
					  				
				break;
			}
			
			case 4:{
		              system("cls");
					  tab[j].aff_inf_anc();				
				break;
			}
			
			case 5:{
		              system("cls");
					  tab[j].calc_age();				
				break;
			}
			
			case 6:{
		              system("cls");
		              cout<<"Entrer l'id de l'infirmier a supprime"<<endl;
		              cin>>cd;
					  if(tab[j].supp_inf(cd))
					  cout<<"**** L'infirmier est supprime avec succes"<<endl;
					  
				break;
			}
			
			case 7:{
		              system("cls");
		              medecin nv;
					  cout<<"Entrer les nouvelles informations du medecin chef"<<endl;
					  nv=creation_md();
					  tab[j].set_med(nv);
					  cout<<"**** Le Medecin chef est modifie avec succes"<<endl;				
				break;
			}
			
			case 8:{
		              system("cls");
					  tab[j].aff_ser();				
				break;
			}
		  }
		cout<<"Voulez vous refaire un autre traitement pour ce service (Entrer 1 pour 'oui' & 0 pour 'non')"<<endl;
        cin>>v;
		
		
	}while(v);
	
    }
    
    else
	cout<<"**** Service introuvable"<<endl;	
	
	}
	
}

cout<<"Voulez vous refaire un autre traitement (Entrer 1 pour 'oui' & 0 pour 'non')"<<endl;
cin>>v;
}while(v);

cout<<"Aurevoir !!"<<endl;
}
