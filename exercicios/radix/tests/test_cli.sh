#!/bin/sh
set -eu
bin="$(pwd)/main"
benchmark="$(pwd)/benchmark"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT HUP INT TERM
cd "$tmp"

if "$bin" </dev/null >saida 2>erro; then
    echo 'Falha: arquivo inexistente deveria retornar erro.' >&2
    exit 1
else
    [ "$?" -eq 1 ]
fi
mkdir in
printf 'invalido\n' >in/tale.txt
if "$bin" </dev/null >saida 2>erro; then
    echo 'Falha: entrada invalida deveria retornar erro.' >&2
    exit 1
else
    [ "$?" -eq 1 ]
fi
if "$benchmark" -r 1 in/tale.txt >saida 2>erro; then
    echo 'Falha: benchmark deveria rejeitar entrada invalida.' >&2
    exit 1
else
    [ "$?" -eq 1 ]
fi
printf '12\nABRACADABRA!' >in/tale.txt
printf 'ABRA\n' | "$bin" >saida
grep -q 'indice 0 do texto: ABRACADABRA!' saida
grep -q 'indice 7 do texto: ABRACADABRA!' saida
printf 'XYZ\n' | "$bin" >saida
grep -q 'Consulta nao encontrada' saida
printf '0\n' >in/tale.txt
printf 'A\n' | "$bin" >saida
grep -q 'Consulta nao encontrada' saida
"$benchmark" -r 1 in/tale.txt >saida
if "$benchmark" -r 0 in/tale.txt >saida 2>erro; then
    echo 'Falha: benchmark deveria rejeitar zero repeticoes.' >&2
    exit 1
else
    [ "$?" -eq 1 ]
fi
if "$benchmark" inexistente.txt >saida 2>erro; then
    echo 'Falha: benchmark deveria rejeitar arquivo inexistente.' >&2
    exit 1
else
    [ "$?" -eq 1 ]
fi
echo 'Consulta e erros de entrada: OK'
