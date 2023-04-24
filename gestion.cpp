#include"gestion.h"

date::date(int a=0,int b=0,int c=0,int d=0,int e=0,int f=0)
{
	j=a;
	m=b;
	this->a=c;
	h=d;
	min=e;
	s=f;
	
}

void date::aff()
{
	cout<<"le "<<j<<"/"<<m<<"/"<<a<<" a "<<h<<"H:"<<min<<"Min:"<<s<<"Sec"<<endl;
}

void date::aff_ag()
{
	cout<<"l'age est :"<<a<<" Ans, "<<m<<" Mois et "<<j<<" Jours"<<endl;
}
date date::age()
{
	date ag;
	time_t now=time(0);
	struct tm newyear = *localtime(&now);
	//year
	ag.a=1900+ newyear.tm_year - a ;
	
	//month
	if(1+newyear.tm_mon<m)
    ag.m=-(1+newyear.tm_mon-m);
    else if(1+newyear.tm_mon>m)
    ag.m=1+newyear.tm_mon-m;
    else
    ag.m=1+newyear.tm_mon;

	//day
	if(newyear.tm_mday<j)
    ag.j=-(newyear.tm_mday-j);
    else if(newyear.tm_mday>j)
    ag.j=newyear.tm_mday-j;
    else
    ag.j=newyear.tm_mday;
    
    ag.h=ag.min=ag.s=0;
    
    return ag;
}

int date::get_annee()
{
	return a;
}

bool date::operator ==(date g)
{
	if (g.a==a && g.m==m && g.j==j && g.h==h && g.min==min && g.s==s)
	return true;
	
	else
	return false;
}

void date::operator =(date g)
{
	j=g.j;
	m=g.m;
	a=g.a;
	h=g.h;
	min=g.min;
	s=g.s;
}
employee::employee()
{
	id="";
	nom="";
	pren="";
	adr="";
	sal=0;
	dat_aff=date();
}

void employee::aff()
{

	cout<<"   l'Id :"<<id<<endl;
	cout<<"   le nom complet :"<<nom<<" "<<pren<<endl;
	cout<<"   l'adresse :"<<adr<<endl;
	cout<<"   le salaire :"<<sal<<" DH"<<endl;
	cout<<"   la date d'affectation :";
	dat_aff.aff();
	
}

void employee::saisie(string a,string b,string c,string d,float f,date g)
{
	id=a;
	nom=b;
	pren=c;
	adr=d;
	sal=f;
	dat_aff=g;
}

string employee::get_id()
{
	return id;
}
medecin::medecin()
{
	employee();
	spe="";
}

int employee::get_age()
{
	return 	dat_aff.get_annee();
}

bool employee::operator ==(employee a)
{
	if(id==a.id && nom==a.nom && pren==a.pren && adr==a.adr && sal==a.sal && dat_aff==a.dat_aff)
	return true;
	
	else
	return false;
}

void employee::operator =(employee e)
{
	id=e.id;
	nom=e.nom;
	pren=e.pren;
	adr=e.adr;
	sal=e.sal;
	dat_aff=e.dat_aff;
	
}
void medecin::saisie(string a,string b,string c,string d,string e,float f,date g)
{
    employee::saisie(a,b,c,d,f,g);
	spe=e;

}

void medecin::aff()
{
	cout<<"les informations du Medecin"<<endl;
	employee::aff();
	cout<<"   la specialite :"<<spe<<endl;
	
}

bool medecin::operator ==(medecin a)
{
	if((employee::operator ==(a)) && (a.spe==spe))
	return true;
	
	else
	return false;
}

void medecin::operator =(medecin m)
{
	employee::operator =(m);
	spe=m.spe;
}

infirmier::infirmier()
{
	employee();
	typ_c="";
}

void infirmier::saisie(string a,string b,string c,string d,string e,float f,date g)
{
	employee::saisie(a,b,c,d,f,g);
	typ_c=e;

}

void infirmier::aff()
{
	cout<<"les informations de l'infirmier"<<endl;
	employee::aff();
	cout<<"   le Type du contrat :"<<typ_c<<endl;
	
}

bool infirmier::comp_inf(infirmier a)
{
	
	if(this->get_id()==a.get_id())
	return true;
	
	else 
	return false;
}

bool infirmier::operator ==(infirmier a)
{
	if((this->operator ==(a)) && (a.typ_c==typ_c))
	return true;
	
	else
	return false;
}

void infirmier::operator =(infirmier m)
{
	employee::operator =(m);
	typ_c=m.typ_c;
}

service::service()
{
	cd="";
	nom="";
	m_chef=medecin();
	n_inf=0;
	t= new infirmier[20];
	date_lanc= date();
}

void service::saisie(string a,string b,medecin c,infirmier* e,date f)
{
	cd=a;
	nom=b;
	m_chef=c;
	n_inf=0;
	t=e;
	date_lanc= f;
	
}
bool service::verif_inf(string a)
{
	for(int i=0;i<n_inf;i++)
	{
		if (t[i].get_id()==a)
		return true;
	}
	
	return false;
}

bool service::ajout_inf(infirmier a)
{
	if(verif_inf(a.get_id()))
    {
	   cout<<"Erreur !! l'infimier existe deja !!"<<endl;
	   return false;
	   
   }
    
    else if (n_inf>20 )
    {
	   cout<<"Erreur !! Vous ne pouvez pas ajouter plus de 20 infimiers !!!"<<endl;
	   return false;
	   
   }    
    else
    {
    	t[n_inf]=a;
    	n_inf++;
    	return true;
	}

}
void service::set_nom(string new_n)
{
	nom=new_n;
}

void service::aff_inf_anc()
{
	cout<<"*****Les infirmiers avec moins de 5 ans d'experience :"<<endl;
	int v=0;
    for(int i=0;i<n_inf;i++)
	{
		if (2022-t[i].get_age()<5)
		{
		t[i].aff();
		v=1;
	    }
	
	}
	
	if(v)
	cout<<"Fin de la liste des infirmiers"<<endl;
	
	else
	cout<<"**** NONE **** \nFin de la liste des infirmiers"<<endl;
}

void service::calc_age()
{
	date p;
	p=date_lanc.age();
	p.aff_ag();
}

bool service::supp_inf(string a)
{
	if(!verif_inf(a))
    {
	   cout<<"Erreur !! l'infimier n'existe pas !!"<<endl;
	   return false;
	   
    }
    
    else
    {
       for(int i=0;i<n_inf;i++)
	        {
		       if (t[i].get_id()==a)
		        {
		        	for(int j=i;j<n_inf;j++)
		        	{
		        		t[j]=t[j+1];
		        		
					}
					n_inf--;
					break;
				}
	        }
	        
	        return true;
	}
}

void service::aff_ser()
{
	cout<<"  ***** Les information du service N'"<<cd<<endl;
	cout<<"  **** le nom du service :"<<nom<<endl;
	cout<<"  *** Date de lancement du service : ";
	date_lanc.aff();
	cout<<"  ** le Medecin chef :"<<endl;
	m_chef.aff();
	cout<<endl;
	cout<<"  * les Infirmiers du service :"<<endl;
	for(int i=0;i<n_inf;i++)
	{
	    t[i].aff();
	}
	cout<<"  *Fin de la liste"<<endl;

}

bool service::operator==(service a)
{
	if(cd==a.cd && nom==a.nom && a.n_inf==n_inf)
	{
		if(a.m_chef==m_chef && a.date_lanc==date_lanc)
		{
			for(int i=0;i<n_inf;i++)
			{
				if(!(a.t[i]==t[i]))
				return false;
			}
			
			return true;
		}
	}
	
	return false;
}

void service::set_med(medecin m)
{
	m_chef=m;
}

date service::get_dat_l()
{
	return date_lanc;
}

string service::get_code()
{
	return cd;
}
void service::operator=(service s)
{
	cd=s.cd;
	nom=s.nom;
	m_chef=s.m_chef;
	n_inf=s.n_inf;
	date_lanc=s.date_lanc;
	
	for(int i=0;i<s.n_inf;i++)
	{
		t[i]=s.t[i];
	}
}
bool verf_serv (service* tab,int n,string an)
{
	for(int i=0;i<n;i++)
	{
		if(tab[i].get_code()==an)
		return true;
	}
	
	return false;
}

bool verf_serv_ind (service* tab,int n,int& j,string an)
{
	for(int i=0;i<n;i++)
	{
		if(tab[i].get_code()==an)
		{ 
		    j=i;
		    return true;
		}
		
	}
	
	return false;
}

bool ajout_ser (service* tab,int& n,service an)
{
	if(verf_serv(tab,n,an.get_code()))
	{
		cout<<"Erreur !! le service existe deja !!!!"<<endl;
		return false;
		
	}
	
	else
	{
		tab[n]=an;
		n++;
		return true;
	}
}


void mod_nom (service s,string nv_n)
{
	s.set_nom(nv_n);
}

void mod_med_ch(service& s,medecin m)
{
	s.set_med(m);
	
}

bool supp_ser (service* tab,int& n,string an)
{
	  if(!verf_serv(tab,n,an))
	{
		cout<<"Erreur !! le service n'existe pas !!!!"<<endl;
		return false;
	}
	
	else
	{
		for(int i=0;i<n;i++)
		{
			if(tab[i].get_code()==an)
			{
				for(int j=i;j<n;j++)
				tab[j]=tab[j+1];
				
				n--;
				break;
			}
		}
		
		return true;
	}
}

void aff_tab_ser(service* tab,int n)
{
	cout<<"\t\t\t\t***** la liste des services est :"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t\t\t***Service n "<<i<<endl;
		tab[i].aff_ser();
	}
	
	cout<<"\t\t\t\t**Fin de la liste"<<endl;
}


service* serv_anc(service* tab,int n,int& n1)
{
	service* tab1=new service[n];
	date ag;
	n1=0;
	
	for(int i=0;i<n;i++)
	{
		ag=tab[i].get_dat_l();
		if(ag.age().get_annee()>10)
		{
			
			tab1[n1]=tab[i];
			n1++;
		}
		
	}
	
	return tab1;
}

date creation_date(int i)
{
	int a,b,c,d,e,f;
	if(i)
	cout<<"***** La date du lancement du service :"<<endl;
	
	else
    cout<<"***** La date d'affectation de l'employee :"<<endl; 
    
    do{
            cout<<"Entrer l'annee :"<<endl;
            cin>>a;
            if(a<1900)
            cout<<"Erreur!!!!!! Entrer une annee Valide"<<endl; 
     }while(a<1900);
     
    do{
            cout<<"Entrer le mois :"<<endl;
            cin>>b;
            if(b<0 || b>12)
            cout<<"Erreur!!!!!! Entrer un mois Valid"<<endl; 
     }while(b<0 || b>12);
	 
    do{
            cout<<"Entrer le jour :"<<endl;
            cin>>c;
            if(c<0 || c>31)
            cout<<"Erreur!!!!!! Entrer un jour Valid"<<endl; 
     }while(c<0 || c>31);
	 
    do{
            cout<<"Entrer l'heure :"<<endl;
            cin>>d;
            if(d<0 || d>23)
            cout<<"Erreur!!!!!! Entrer une heure Valide"<<endl; 
     }while(d<0 || d>23);	  
	 	      
    do{
            cout<<"Entrer les minutes :"<<endl;
            cin>>e;
            if(e<0 || e>59)
            cout<<"Erreur!!!!!! Entrer un nombre Valid"<<endl; 
     }while(e<0 || e>59);	 	      

    do{
            cout<<"Entrer les secondes :"<<endl;
            cin>>f;
            if(f<0 || f>59)
            cout<<"Erreur!!!!!! Entrer un nombre Valid"<<endl; 
     }while(f<0 || f>59);	 	      
     
    date nw(c,b,a,d,e,f);
    return nw;
}

medecin creation_md()
{
	string id,nom,pren,adr,spe;
	float sal;

	
	cout<<"Entrer l'id du Medecin :"<<endl;
	cin>>id;
	cout<<"Entrer le nom du Medecin :"<<endl;
	cin>>nom;
	cout<<"Entrer le prenom du Medecin :"<<endl;
	cin>>pren;
	cout<<"Entrer la specialite du Medecin :"<<endl;
	cin>>spe;
	cout<<"Entrer l'adresse du Medecin :"<<endl;
	cin>>adr;
	cout<<"Entrer le salaire du Medecin :"<<endl;
	cin>>sal;
	date d = creation_date(0);
	
	medecin e;
	e.saisie(id,nom,pren,adr,spe,sal,d);
	
	return e;
}

infirmier creation_infi()
{
	string id,nom,pren,adr,spe;
	float sal;

	
	cout<<"Entrer l'id du L'infirmier :"<<endl;
	cin>>id;
	cout<<"Entrer le nom du L'infirmier :"<<endl;
	cin>>nom;
	cout<<"Entrer le prenom L'infirmier :"<<endl;
	cin>>pren;
	cout<<"Entrer le type du contrat de L'infirmier :"<<endl;
	cin>>spe;
	cout<<"Entrer l'adresse du L'infirmier :"<<endl;
	cin>>adr;
	cout<<"Entrer le salaire L'infirmier :"<<endl;
	cin>>sal;
	
	date d = creation_date(0);
	infirmier e;
	e.saisie(id,nom,pren,adr,spe,sal,d);
	
	return e;
	
}

service creation_ser()
{
	string cd,nom;
	medecin m_chef;
	int n_inf,v;
	infirmier* t = new infirmier[20];
	date date_lanc;
	service s;
	
	cout<<"  Entrer le code du Service :"<<endl;
	cin>>cd;
	
	cout<<"  Entrer le nom du Service :"<<endl;
	cin>>nom;
	
	cout<<"  Entrer les informations de Medecin Chef :"<<endl;
	m_chef=creation_md();
	
	date d = creation_date(1);
	
	cout<<"  Entrer le nombre d'infirmiers dans le Service :"<<endl;
	cin>>n_inf;
	s.saisie(cd,nom,m_chef,t,d);
	
	cout<<"  Entrer la liste d'Infirmier :"<<endl;
	for(int i=0;i<n_inf;i++)
	{ v=0;
	
	do{
		cout<<"L'infirmier N' "<<i<<endl;
		if(!(s.ajout_inf(creation_infi())))
		{  
		   cout<<"Veuillez le Rentrer !!!!"<<endl;
		   v=1;
	    }
		else
		v=0;
      }while(v);

		
	}

	
	return s;

}

int menu1()
{
	system("cls");
	cout<<"\t\t\t\t******* MENU TRAITEMENT DU SERVICE *******"<<endl;

	cout<<"1-Verifier l'existance d'un infirmier"<<endl;
	cout<<"2-Ajouter un infirmier"<<endl;
	cout<<"3-Modifier le nom"<<endl;
	cout<<"4-Afficher les infirmiers ayant moins de 5 ans d’expérience"<<endl;
	cout<<"5-Obtenir l'age"<<endl;
	cout<<"6-Supprimer un infirmier"<<endl;
	cout<<"7-Modifier les informations du medecin chef"<<endl;
	cout<<"8-Afficher toutes les informations"<<endl;
	
	int a;
	cout<<"*****Entrer votre choix : "<<endl;
	cin>>a;
	
	return a;
	
}

int menu()
{
	system("cls");
	cout<<"\t\t\t\t********************"<<endl;
	cout<<"\t\t\t\t******* MENU *******"<<endl;
	cout<<"\t\t\t\t********************"<<endl;
	
	cout<<"1-Ajouter un Service"<<endl;
	cout<<"2-Verfier l'existance d'un service"<<endl;
	cout<<"3-Supprimer un Service"<<endl;
	cout<<"4-Afficher les Services avec leurs informations"<<endl;
	cout<<"5-Afficher les Services avec 10 ans d'experience"<<endl;
	cout<<"6-Traiter un Service"<<endl;
	
	int a;
	cout<<"*****Entrer votre choix : "<<endl;
	cin>>a;
	
	return a;
}
