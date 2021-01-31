Test 1: #1 Declaração de variáveis
Test 2: #2 Atribuição e contas
Test 3: #3 if sem else
Test 4: #4 if com else
Test 5: #5 Objetos e arrays
Test 6: #6 while
Test 7: #7 for
Test 8: #8 multiplicação de matrizes
Test 9: #9 Variável não declarada
Test 10: #10 Declaração duplicada da mesma variável
Test 1: #1 Declaração de variáveis
Incorrect program result
--- Input ---

let a = {}, b = [], c = 9;
let \__9 = 1.1;
let _ = "abc";

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ \_: abc; \_\_9: 1.1; a: { }; b: [ ]; c: 9; }|
=== Pilha ===

Test 2: #2 Atribuição e contas
Incorrect program result
--- Input ---

let a = 1, b, x;
x = b = a \* 8 + 1.1;
let c = "hello ";
c = c + ", " + 'world' + '!';

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (text)---

=== Console ===
=== Vars ===
|{ a: 1; b: 9.1; c: hello , world!; x: 9.1; }|
=== Pilha ===
"

Test 3: #3 if sem else
Incorrect program result
--- Input ---

let a = 4, b = 5, c, d;
if( a > b )
c = "a e' maior" + "!";
if( a < b + 1 )
d = "a e' menor";

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ a: 4; b: 5; c: undefined; d: a e' menor; }|
=== Pilha ===

Test 4: #4 if com else
Incorrect program result
--- Input ---

let a = "ABA", c = 'CATE', resultado;
if( a == c )
resultado = "Ta' errado!";
else if( a < c ) {
resultado = "a vem antes de c: ";
resultado = resultado + a + '<' + c;
}
else
resultado = "Deu ruim!";

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ a: ABA; c: CATE; resultado: a vem antes de c: ABA<CATE; }|
=== Pilha ===

Test 5: #5 Objetos e arrays
Incorrect program result
--- Input ---

let obj = {}, i = -2;
obj.nome = "Manoel";
obj.nums = [];
obj.nums[0] = 12;
obj.nums[3] = 13;
obj.nums[i+3] = 45;
obj['nom' + 'e'] = obj.nome + "!";

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: obj

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ i: -2; obj: { nome: Manoel!; nums: [ 0: 12; 1: 45; 2: undefined; 3: 13; ]; }; }|
=== Pilha ===

Test 6: #6 while
Incorrect program result
--- Input ---

let i = 0, j = -1, x = 9, b = [];
while( i < x - 2\*3 + 2.1 ) {
b[i] = j;
i = i + 1;
j = i / 2.0 + j;
}
j = x = 0;

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: i

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ b: [ 0: -1; 1: -0.5; 2: 0.5; 3: 2; 4: 4; 5: 6.5; ]; i: 6; j: 0; x: 0; }|
=== Pilha ===

Test 7: #7 for
Incorrect program result
--- Input ---

let a = {}, campo = "c";
for( let i = 0; i < 6; i = i + 2 ) {
a[campo = campo + i] = i;
}

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ a: { c0: 0; c02: 2; c024: 4; }; campo: c024; i: 6; }|
=== Pilha ===

Test 8: #8 multiplicação de matrizes
Incorrect program result
--- Input ---

let a = [], b = [], c = [];
let i, j, k;
for( i = 0; i < 4; i = i + 1 ) {
a[i] = [];
b[i] = [];
for( j = 0; j < 4; j = j + 1 ) {
a[i][j] = b[i][j] = 1.1/(i+j+1.0);
}
}

for( i = 0; i < 4; i = i + 1 ) {
c[i] = [];
for( j = 0; j < 4; j = j + 1 ) {
c[i][j] = 0;
for( k = 0; k < 4; k = k + 1 ) {
c[i][j] = c[i][j] + a[i][k] \* b[k][j];
}
}
}

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

=== Console ===
=== Vars ===
|{ a: [ 0: [ 0: 1.1; 1: 0.55; 2: 0.366667; 3: 0.275; ]; 1: [ 0: 0.55; 1: 0.366667; 2: 0.275; 3: 0.22; ]; 2: [ 0: 0.366667; 1: 0.275; 2: 0.22; 3: 0.183333; ]; 3: [ 0: 0.275; 1: 0.22; 2: 0.183333; 3: 0.157143; ]; ]; b: [ 0: [ 0: 1.1; 1: 0.55; 2: 0.366667; 3: 0.275; ]; 1: [ 0: 0.55; 1: 0.366667; 2: 0.275; 3: 0.22; ]; 2: [ 0: 0.366667; 1: 0.275; 2: 0.22; 3: 0.183333; ]; 3: [ 0: 0.275; 1: 0.22; 2: 0.183333; 3: 0.157143; ]; ]; c: [ 0: [ 0: 1.72257; 1: 0.968; 2: 0.685667; 3: 0.533937; ]; 1: [ 0: 0.968; 1: 0.560969; 2: 0.403333; 3: 0.316905; ]; 2: [ 0: 0.685667; 1: 0.403333; 2: 0.292081; 3: 0.230476; ]; 3: [ 0: 0.533937; 1: 0.316905; 2: 0.230476; 3: 0.18233; ]; ]; i: 4; j: 4; k: 4; }|
=== Pilha ===

Test 9: #9 Variável não declarada
Incorrect program result
--- Input ---

let a = 1, x = '9';
b = 10;

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

Erro: a variável 'b' não foi declarada.

Test 10: #10 Declaração duplicada da mesma variável
Incorrect program result
--- Input ---

let a = {}, b = [], c = 9;
let a;

--- Program output ---

=== Console ===
0: let
1: Erro
2: :
3: syntax
4: error
5: Perto
6: de
7: :
8: a

=== Erro: Instrução inválida: : ===
=== PC: 2 ===
=== Vars ===
|{ }|
=== Pilha ===
|let|
|Erro|

--- Expected output (exact text)---

Erro: a variável 'a' já foi declarada na linha 1.

Summary of tests

+------------------------------+
| 10 tests run/ 0 tests passed |
+------------------------------+
