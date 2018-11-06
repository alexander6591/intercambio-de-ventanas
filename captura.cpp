#include <iostream>
#include <windows.h>

using namespace std;

//declaracion de variables globales

int interMS;//intervalo de micro-segundos
int sm=0, s=0,m=0,h;//sirve para el cronometro
int intervalo;//intervalo en segundos
int cam,cons;//variables con las cuales vas a entrar en el void
bool local=true;//ayuda para que no entre donde no debe
bool amenudo=true;//ayuda para que no entre donde no debe x2

//aqui se metera en el primer valor que le des
void cambioLocal(void){
	
	if(local==false){
		
		int i=1;

		cout<<i;
			while(i<=cons){
	
				//naruto(relleno), servia para saber si entraba al puto bucle
				/*cout<<"entro-1 ",i;*/
				
				i++;
				cout<<i;
				Sleep(2000);//el programa espera 2 segundos
				keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
				keybd_event(VK_TAB,0x8f,0 , 0);//tab press
				Sleep(2000);//el programa espera 2 segundos

		}
	
		keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
		keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release
		local=true;//hace que no pueda volver a entrar aqui al menos que se ejecute el siguiente void
		amenudo=false;//hace posible entrar al siguiente void
		cons=1;//con esto se sabra que solo tiene quedarle un tab para llegar al programa
		
	}


Sleep(interMS);//tiempo que se va a esperar para que inicie el siguiente codigo
}

//aqui se metera con el segundo valor que le diste
void cambioAmenudo(void){
	
	if(amenudo==false){	
		int i=1;


		while(i<=cam){

			//naruto(relleno), servia para saber si entraba al puto bucle
			/*cout<<"entro-2 ",i;*/
			
			i++;
			Sleep(2000);//el programa espera 2 segundos
			keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
			keybd_event(VK_TAB,0x8f,0 , 0);//tab press
			Sleep(2000);//el programa espera 2 segundos

		}
		
		keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
		keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release
		local=false;//hace posible entrar al anterior void
		amenudo=true;//hace que no pueda volver a entrar aqui al menos que se ejecute el anterior void
		cam=1;
	}
Sleep(interMS);//tiempo que se va a esperar para que inicie el siguiente codigo
}

//el mismo void dice que es un conometro ._. y con este podemos darle un tiempo entre la ejecucion del programa
void cronometro (void){
	
	 for(h=0; h<12; h++){
	 	
		for(m =0; m<60; m++){
			
			for(s=0; s<60; s++){
				system("cls");
				cout <<"\t\t\t\t" <<h << ":" << m << ":" << s << endl;
				Sleep(1000); 
				system("cls");
					//confima si el intervalo se ha cumplido(solo funciona en segundos)
					if (s==intervalo ){
			
		
						if (local==false){
	
							cambioLocal();//se va al primer void
						}
		
						if (amenudo==false){
							cambioAmenudo();//se va al segundo void
						}
		
					}				
			}
		}
	}

}

//es el main ._. donde se inicia el programa >:v/
int main()
{

	bool valores=true;//para que entre donde ingresas los valotres

//donde ingresas los valores
	if(valores==true){
		//para que entre en el primer void y no enel segund
		local=false;
		amenudo=true;
		
		cout<<"ventana de donde quieres conservarse >";
		cin>>cons;
		cout<<"ventana de donde quiere cambiar amenudo >";
		cin>>cam;
		cam=cam+1;
		cout<<"intervalo entre cada ventana en segundos >";
		cin>>intervalo;
		interMS=intervalo*1000;//multiplica el intervalo por 1000 para ponerlo en los momentos de espera
		valores=false;//para que no vuelva entrar aqui mas nunca
		
	}
		
		//para que se quede en un bucle infito
	do{
		cronometro();//entra al void cronometro
		s=0;//pone los segundos en 0 para volver iniciar el programa desde 0
	}while(true);

    return 0;
}

