function ayuda() { #funcion de ayuda
cat << ayuda_des #mensaje de ayuda
Debe introducir mas de un parametro, o el parametro que introdujo
esta erroneo.
Corra el programa e intenta poner el parametro justo al terminar "sh"
ayuda_des
}
if test $# -le 0 ; then  #comprueba los parametros
	echo "Hay que introducir al menos un parametro"
	ayuda #imprime la ayuda
	exit 1
fi
msg="Hola" #mensaje predeterminado
a=1 #verificador
while [ -n "$1" ]; do #bucle mientras haya parametros
	if [$a -eq 1 ]; then #concantena el mensaje
		msg="$msg $1"
		a=0
	else
		msg="$msg, $1"
	fi
	shift
done
echo $msg"!" #Imprimiendo el mensaje final
exit 0
