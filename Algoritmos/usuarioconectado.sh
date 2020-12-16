function ayuda() {
cat << ayuda_des
	$0 Usuario
	SI si el usuario esta conectado
	NO si el usuario no esta conectado
ayuda_des
}
if [ $# -ne 1 ]; then #comprueba  la cantidad de parametro ingresado
	echo "Debe haber al menos un parametro"
	ayuda #envia mensaje de ayuda
	exit 1
fi
conectado = 'who | grep $1' #comprueba el si el usuario esta conectado
if [ -z "$conectado" ]; then #dependiendo de la variable contesta
	echo "NO" #no si no esta conectado
else 
	echo "SI" #si si esta conectado
fi

