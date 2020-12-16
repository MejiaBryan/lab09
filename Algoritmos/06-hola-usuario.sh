function ayuda(){
cat << ayuda_des #mensaje de ayuda
El usuario ingreso no es valido ingrese un usuario valido
Puede correr de nuevo el programa e ingresar uno
acontinuacion de "sh"
ayuda_des
}
if [ $# -le 0 ] ; then #si el numero de parametros es menor a 0
	echo "Introducir al menos 1 parametro"
	ayuda
	exit 1
fi
msg="Hola" #Mensaje predeterminado
a=1 #verificador
while [ -n "$1" ]; do #bucle mientras haya parametros
	conectado=who | grep '$1'
	if [ -z "$conectado" ]; then #verifica si esta conectado
		echo "El usuario $1 no esta conectado"
		ayuda #mensaje de ayuda
		exit 2
	fi
	if [ $a -eq 1 ]; then #si esta el usuario aun
		msg="$msg $1" #concatenando mensaje
		a=0 #verificador
	else
		msg="$msg, $1" #concatenando con la ,
	fi
	shift
done
echo ${msg}"!" #imprimiendo mensaje

