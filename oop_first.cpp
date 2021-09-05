#include <iostream>
using std::string;

//aggiungeremo i membri della classe:
//attributi e i comportamenti
class Employee{
private:
	string Name;
	string Company;
	int Age;
public:
	//mi creo i metodi setter e getter per i dati della classe essendo private
	void setName(string name){ //riceve una stringa name e modifica il dato Name della classe settandolo = a name
		Name = name;
	}
	string getName(){ //funzione get restituisce una stringa Name
		return Name;
	}
	void setCompany(string company){
		Company = company;
	}
	string getCompany(){
		return Company;
	}
	void setAge(int age){
		if(age >= 100){
			std::cout << "\n-----------------------\n";
			std::cout << "VECCHIO DI MERDA" << std::endl;
			Age = age;
		}else if(age >= 18){
			std::cout << "\n-----------------------\n";
			std::cout << "PUOI ANDARE IN GALERA TRANQUILLAMENTE" << std::endl;
			Age = age;
		}
		
				
	}
	int getAge(){
		if(Age >= 100){
			std::cout << "SEI VECCHIO" << std::endl;
			return Age;
		}else if(Age >= 18){
			std::cout << "si, non fare cazzate che sei maggiorenne" << std::endl;
			return Age;
		}else if(Age > 0 && Age < 18){
			std::cout << "Sei piccolo";
			return Age;
		}else{
			std::cout << "o non sai contare oppure non sei ancora nato....decidi tu";
			return Age;
		}
	}
	
	
	//string Name;
	//string Company;
	//int Age;
	//3 attributi. se ne possono aggiungere infiniti
	//tutti gli attributi di default sono private
	//private :non è accessibile al difuori della classe. Hidden fuori dalla classe
	//public : è accessibile da tutti (meretrice)
	//protected : è una via di mezzo tra le due
	
	
	//creo un metodo che l'utente Employee utilizza
	
	//Presentazione
	//creo una funzione che mi restituisce in output il nome dell'employee, l'azienda dove lavora e l'età
	void IntroduceYourself(){
		std::cout<<"Name : " << Name << std::endl;
		std::cout<<"Company : " << Company << std::endl;
		std::cout<<"Age : " << Age << std::endl;
	}
	
	//se non creiamo nessun costruttore il compilatore setterà un costruttore di default che setterà le variabili in un determinato modo
	//punti per la creazione di un costruttore
	//1 following : il costruttore è un metodo ma sPeCiAlE. A differenza degli altri metodi non ha un return quindi non restituisce niente anche se non è di tipo void(le funzioni void non restituiscono niente)
	//2 Name : il costruttore ha lo stesso nome della classe alla quale appartiene (classe: Employee Nome_costruttore: Employee)
	//3 Public : il costruttore dev'essere publico (non sempre, ci sono determinate situazioni dove il costruttore può essere private oppure protected
	
	Employee(string name, string company, int age){ //al costruttore passiamo il nome di tipo string, la compagnia di tipo string e l'etò di tipo int
		Name = name;
		Company = company;
		Age = age;
	}
	
	/*
	private: 
		Employee(){
		}
	otterremmo un errore quando dichiariamo gli oggetti della classe perchè non riuscirebbero ad accedere al costruttore in quanto è private
	*/ 
};

int main(){
	//creo l'istanza della classe 
	int number; //specifico prima il tipo e poi il nome
	Employee employee1 = Employee("Luca", "Telecosmo", 23); //emplyeel è di tipo Employee;
	//per accedere nome variabile di tipo classe . nome della variabile alla quale si vuole accedere
	//employee1.Name; //non restituisce niente perchè è ancora vuoto il contenuto
	//employee1.Name; con il protected non sarà accessibile
	//employee1.Name = "Luca";
	//employee1.Company = "Telecosmo";
	//employee1.Age = 23;
	
	//employee1.Name;
	//employee1.Company;
	//employee1.Age;
	
	std::cout << "employee n1" << std::endl;
	std::cout << "------------" << std::endl;
	
	employee1.IntroduceYourself(); //richiamo la funzione della classe Employee
	
	//creiamo un nuovo employee di tipo Employee
	Employee employee2 = Employee("Giovanni", "Ditta insaccati", 23); //passo al costruttore i dati che mi servono (name, company , age)
	
	
	//employee2.Name = "Giovanni";
	//employee2.Company = "Telecosmo";
	//employee2.Age = 23;
	
	std::cout << "employee n2" << std::endl;
	std::cout << "------------" << std::endl;
	
	employee2.IntroduceYourself();
	
	//quello di ripetere ogni volta i metodi e la dichiarazione degli attributi della classe è un metodo sbagliato
	//se dobbiamo registrare milioni di employees dovrammo ripetere milioni di volte le stesse righe di codice 
	//a risolvere questo problema ci pensa il costruttore
	//il costruttore è un tipo speciale di metodo che viene richiamato ogni volta che devo creare un oggetto della classe
	//ad esempio verrebbe richiamato quando scrivo "Employee employee1"
	
	//ENCAPSULATION
	//consiste nel legare insieme i dati e i metodi insieme in modo da tenere la classe compatta
	//viene fatto perchè diamo una protezione ai metodi e ai dati di una determinata classe in modo tale che un utente esterno no possa accedere a determinati dati nelle classi e a determinati dati nei metodi usati
	//non vuol dire che i dati non possano essere modificati anzi, solo che viene fatto in modo da non permettere ad altre classi o metodi di modificare direttamente i dati 
	//in modo tale da creare un mio modo per far si che le altre classi modificano i dati
	//accedo ai dati attraverso i metodi : getter o setter 
		
	employee1.setAge(100);
	std::cout<<employee1.getAge()<<" eta' modificata di " << employee1.getName() << std::endl;
	std::cout<<employee2.getAge() << "eta' di " << employee2.getName() << std::endl;
	
	Employee employee3 = Employee("Giacomo", "A-cus", 0);
	
	std::cout << employee3.getName() << "la tua eta' e'" << employee3.getAge() << std::endl; 
}
