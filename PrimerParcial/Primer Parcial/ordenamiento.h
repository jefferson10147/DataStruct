template <class t>
void cambio (t &a, t &b){
	t aux = a;
	a = b;
	b = aux;
}

template <class t>
void shakerSort(t v[], int n)
{
	int inicio = 0, final = n-1;
	int aux;
	bool band = false;
	do {
		if(!band) {

			for(int i = 0;i < final;i++)
				if(v[i] > v[i+1])
					swap (v[i], v[i+1]);


			band = true;
			final--;
		}
		if(band) {

			for(int i = final ;i > inicio;i--)
				if(v[i] < v[i-1])
					swap (v[i],v[i-1]);

			band = false;
			inicio++;
		}
	} while(inicio < final);
}
