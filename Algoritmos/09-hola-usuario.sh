function ayuda(){ #mensaje de ayuda
cat << ayuda_des
	1 Si los datos no son como minimo 1
	2 El usuario no esta conectado
ayuda_des
}
if [ $# -le 0 ] ; then #Verifica que al menos haya un parametro
	echo "Ingresar al menos un parametro"
	ayuda
	exit 1
fi
msg="Hola" #mensaje predeterminado
a=1 #verificador
while [ -n "$1" ]; do #bucle para el usuario conectado
	conectado='./usuarioconectado $1' #guarda usuario conectado de usuarioconectado.sh
	if [ "$conectado" == "NO" ]; then #si no esta conectado
		echo "El usuario $1 desconectado" #Nos dice que no esta conectado
		ayuda
		exit 2
	fi
	if [ $a -eq 1 ]; then #Si esta conectado entonces manda el mensaje 
		msg="$msg $1"
		a=0
	else
		msg="$msg, $1" #concatena el mensaje con coma
	fi
	shift
done
echo ${msg}"!" #imprime la variable donde guardamos el mensaje 
