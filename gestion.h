#include<iostream>
#include<string>
#include<ctime>
#include<cctype>
using namespace std;

class date{
	int j,m,a,h,min,s;
	
	public:
	date(int,int,int,int,int,int);
	void aff();
	date age();
	void aff_ag();
    int get_annee();
    bool operator == (date);
    void operator = (date);

};

class employee
{
	string id,nom,pren,adr;
	float sal;
	date dat_aff;
	
	public:
	employee();
	string get_id();
	void aff();
	void saisie(string,string,string,string,float,date);
	int get_age();
	bool operator == (employee);
	void operator = (employee);

	
};
class medecin : public employee
{
	string spe;
	
	
	public:
	medecin();
	void aff();
	void saisie(string,string,string,string,string,float,date);
	bool operator == (medecin);
	void operator = (medecin);
	
	
	
};
class infirmier : public employee
{
	string typ_c;

	
	public:
		infirmier();
		void aff();
		void saisie(string,string,string,string,string,float,date);
		bool comp_inf(infirmier a);
		bool operator == (infirmier);
		void operator = (infirmier);
	
};

class service 
{
	string cd,nom;
	medecin m_chef;
	int n_inf;
	infirmier* t;
	date date_lanc;
	
	public:
		service();
		void saisie(string,string,medecin,infirmier*,date);
		bool verif_inf(string);
		bool ajout_inf(infirmier);
		void set_nom(string);
		void aff_inf_anc();
		void calc_age();
		bool supp_inf(string);
		void aff_ser();
		bool operator== (service);
		void set_med(medecin);
		date get_dat_l();
		void operator= (service);
		string get_code();
		
};

bool verf_serv(service*,int,string);
bool verf_serv_ind (service*,int,int&,string);
bool ajout_ser(service*,int&,service);
void mod_nom(service,string);
void mod_med_ch(service&,medecin);
bool supp_ser(service*,int&,string);
void aff_tab_ser(service*,int);
service* serv_anc(service*,int,int&);
date creation_date(int);
infirmier creation_infi();
medecin creation_md();
service creation_ser();
int menu();
int menu1();
