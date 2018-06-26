---
title: Abhi's Website 
layout: common/page
nav:
  'Sul problema di Apollonio': './'
  'Soluzione Euristica': '#soluzione-euristica'
  Iterazione: '#iterazione'
---

# Sul problema di Apollonio

> Sulle rive di uno stagno, passò un satiro e La vide,
> Reginella sempre bella, è la musica di Euclide.
> È all'identità, il riflesso, ciò a cui diede movimento,
> ben tre sassi egli lanciò, distribuendoli nel vento.
> Poi dall'ombra nacque un fiore,
> tre fu il fischio della voce.

<style>
  circle {
    fill: transparent;
    stroke: black;
  }
</style>

Apollonio da Perga (terzo secolo a.C.) fu, assieme ad Euclide e al nostro Archimede, uno dei più grandi matematici dell'antichità. In un'opera chiamata **Tangenze**, propone un problema molto interessante:

> Dati tre cerchi tangenti a due a due,

<svg
  xmlns="http://www.w3.org/2000/svg"
  viewBox="0 0 200 200"
  height="200"
  width="200"
>
  <circle cx="100" cy="60" r="50"/>
  <circle cx="170" cy="70" r="20"/>
  <circle cx="155" cy="115" r="27"/>
</svg>

> trovare un cerchio tangente a tutti e tre

Purtroppo gli scritti originali sono persi nella storia e la soluzione data da Apollonio non è pervenuta fino a noi, ma, per fortuna conosciamo il problema grazie ad una citazione di [Pappo](https://it.wikipedia.org/wiki/Pappo_di_Alessandria). Studierò questo problema e la sua iterazione muovendomi lungo il sentiero che l'ispirazione mi ha tracciato.

<svg
  xmlns="http://www.w3.org/2000/svg"
  viewBox="0 0 400 400"
  height="400"
  width="400"
>
  <circle cx="140" cy="160" r="100"/>
  <circle cx="140" cy="160" r="105" stroke-dasharray="5, 5"/> <!-- r + 5 -->
  <circle cx="140" cy="160" r="120" stroke-dasharray="5, 5"/> <!-- r + 20 -->

  <circle cx="279" cy="142" r="40"/>
  <circle cx="279" cy="142" r="45" stroke-dasharray="5, 5"/> <!-- r + 5 -->
  <circle cx="279" cy="142" r="60" stroke-dasharray="5, 5"/> <!-- r + 20 -->

  <circle cx="273" cy="232" r="50"/>
  <circle cx="273" cy="232" r="55" stroke-dasharray="5, 5"/> <!-- r + 5 -->
  <circle cx="273" cy="232" r="70" stroke-dasharray="5, 5"/> <!-- r + 20 -->
</svg>

## Soluzione Euristica

Siano tre cerchi tangenti a due a due, se si espandono come le onde di tre sassi lanciati in uno stagno, c'è un instante nel quale i tre cerchi passano per lo stesso punto.
Questo punto si trova all'interno della zona detta *triangolo curvilineo*, delimitata dai tre cerchi iniziali ed è il centro del cerchio da trovare!
Infatti se ho due cerchi tangenti di raggi $$R$$ ed $$r$$ e voglio trovare un cerchio di raggio $$\rho$$ tangente ai due, li espando fino a che i raggi siano $$R+\rho$$ e $$r+\rho$$. Uno dei punti in comune dei nuovi cerchi può essere il centro del cerchio di raggio $$\rho$$.

<!-- Animazione con i tre cerchi tangenti che si espandono
     ... come tre sassi lanciati in uno stagno -->

Se esiste una soluzione del *Problema di Apollonio* (PdA), si può applicare questa espansione ai tre cerchi tangenti a due a due per trovare il cerchio richiesto.
Ma l'espansione di cui si parla non è una trasformazione del piano in se stesso, non è neanche bigettiva.
Per andare avanti userò la geometria che sembra essere la più naturale per questo argomento: la *geometria inversiva* nel piano.
Inoltre esistono due soluzione del PdA: oltre al cerchio che si trova all'interno del triangolo curvilineo ce n'è anche uno esterno che è tangente ai tre cerchi iniziali.

<!-- figura con le due soluzioni del PdA -->

<svg
  xmlns="http://www.w3.org/2000/svg"
  viewBox="0 0 200 200"
  height="300"
  width="300"
>
  <circle cx="100" cy="100" r="100"/>
</svg>

## Soluzioni del Problema di Apollonio

In questo capitolo ci sono tre soluzioni del PdA. Ognuna è indipendente dalle altre ma nei capitoli successivi si uniranno nello studio dell'iterazione del PdA. Esiste anche una soluzione con riga e compasso, credo sia di Hartshorne.

### Introduzione alla Geometria Inversiva

Sperando di sistemare, con poco sforzo per il lettore, un'esaudiente introduzione alla geometria inversiva, comincio con la seguente

#### definizione 1

Siano dati un segmento $$AB$$ ed una constante positiva $$K$$, definisco $$\Gamma$$ come il luogo dei punti $$P$$ tali che

$$
AP = K \cdot PB
$$

Il lettore può sempre scegliere la dimensione $$n$$ dello spazio euclideo in cui cercare i punti del luogo $$\Gamma$$.
Le proposizioni che seguono mi servono per la soluzione inversiva del PdA ma sono valide per ogni $$n>0$$. Per ora suggerisco di porre

$$
n=1
$$

cioè di guardare solo la retta $$s$$ passante per $$AB$$

<!-- disegno retta -->

Se $$K=1$$ il luogo $$\Gamma$$ è semplicemente il punto medio tra A e B. Se k diverso 1 è composto da due punti, siano C e D.

**esercizio 1** *Si considerino i punti A=0 e B=3 sulla retta dei reali. Trovare i punti C e D del luogo gamma2 = { insieme dei punti P tali che AP = 2 BP }*

Risulta che AC = K BC quindi

AB = AC + BC = K BC + BC = ( K + 1 ) BC

e, analogamente, AD = K BD quindi

AB = AD - BD = K BD - BD = (K - 1) BD

Segue che

<!-- formula -->

e

<!-- formula -->

Inoltre

<!-- formula -->

da cui si ricava che <!-- formula --> che ha senso perchè si suppone $$K \neq 1$$. Fissato il segmento $$AB$$, questa ultima relazione permette di muovere il luogo $$\Gamma$$ al variare di $$K$$.

**esercizio 2** *Si prenda la retta reale con A = -1, B=1 e K appartenente (1,infinito). Esprimere i punti C e D in funzione di K.*

#### definizione 2 (inversione di centro O e raggio r)

L'immagine di un punto $$P$$, diverso da $$O$$, è il punto $$Q$$ che sta sulla semiretta $$OP$$ uscente dal centro $$O$$ e tale che

$$
OP OQ = r2*
$$

Si $$AB$$ il segmento $$[-1, 1]$$ e, come nell'esercizio precedente, si trasformi con l'inversione di centro zero e raggio uno. Si scelga la constante $$K$$ e si trovino i punti $$C$$ e $$D$$ corrispondenti.
Attenzione! Non si può ancora considerare il luogo $$\Gamma$$ perchè coincide proprio con $$O$$ che, per adesso, non si può invertire. In particolare, l'espressione analitica di questa trasformazione è

$$
x \mapsto \frac{1}{x}
$$

Ecco alcune proprietà:

* i punti $$A$$ e $$B$$ sono fissi,
* l'immagine di $$C$$ è $$D$$, e viceversa, infatti $$OC \cdot OD = 1$$,
* l'interno del segmento $$AB$$ si scambia con l'esterno,
* è una trasformazione involutiva, cioè è inversa di sè stessa.

Ma dove va a finire il punto $$O$$? Per saperlo bisogna definire l'ambiente dove si svolge la geometria inversiva, cioè dove ogni inversione è una bigezione.
Occorre aggiungere un punto *ideale* che sia l'immagine di $$O$$, mantendendo le proprietà viste prima.

#### definizione 3 (retta inversiva S1)

É la retta $$s$$ con un punto in più a cui si attribuisce i simbolo $$\infty$$.

Si sceglie questo nome per il punto aggiunto proprio perchè, al crescere di $$K$$, il punto $$C$$ si avvicina ad $$O$$ e di conseguenza $$OD$$ aumenta. Niente paura, la retta inversiva si può immaginare come un cerchio e per passare da $$s$$ a $$S^1$$ si può usare la

<!-- figura proiezione stereografica 1-dimensionale -->

Ma ci sono altri punti nel luogo $$\Gamma$$? Se si suppone che esista un altri punto $$P$$ appartenente a $$\Gamma$$ che non sia allienato con la retta $$s$$, si può guardare nel piano $$\Pi$$ contenente quel punto $$P$$ e la retta $$s$$

<!-- figura -->

d'ora in avanti si pone

$$
n = 2
$$

per sviluppare gli strumenti di geometria inversiva che servono a risolvere il PdA. Tanto per cominciare il luogo gamma1 è una retta, precisamente, l'asse del segmento $$AB$$.

Il piano inversivo $$S^2$$ si può immaginare come la superficie di una sfera dove il punto all'infinito è il polo nord. Disegnare nel piano inversivo è come diseganre su un pallone dove le rette sono le circonferenze passanti per il polo nord. Non può mancare nella geometria inversiva questa

#### definizione 4 (birapporto inversivo)

Da non confondere con il birapporto proiettivo, presi quattro punti distinti $$A, B, C, D$$ è definito come segue

$$
{AB, CD} = \frac{AC \cdot BD}{AD \cdot BC}
$$

#### Proposizione 1

Il birapporto è invariante per le trasformazioni della geometria inversiva.

Sia l'inversione di centro $$O$$, raggio $$r$$ e siano i punti come in figura

<!-- figura -->

dove $$OA \cdot OA' = r^2 = OB \cdot OB'$$. Allora $$OB : OA' = OA : OB'$$ e $$OAB \sim OA'B$$. I triangoli sono simili, avendo due lati in proporzione ed un angolo comune in O. <!--formula inline --> quindi <!-- formula inline -->.
Se prendo quattro punti distinti $$A, B, C, D$$ e ne calcolo il birapporto $$\{AB, CD\}$$, poi trasformo con un'inversione e ottengo altri punti $$A', B', C', D'$$ e ne calcolo il birapporto risulta

$$
\{AB, CD\} = \{A'B', C'D'\}
$$

questo significa che il birapporto si conserva i.e. è un invariante della geometria inversiva. Facendo il conto

$$
\{A'B', C'D'\}
= \frac{A'C' \cdot B'D'}{A'D' \cdot B'C'}
= \frac{
    \frac{r^2 \cdot AC}{OA \cdot OC}
      \cdot
    \frac{r^2 \cdot BD}{OB \cdot OD}
  }{
    \frac{r^2 \cdot AD}{OA \cdot OD}
      \cdot
    \frac{r^2 \cdot BC}{OB \cdot OC}
  }
= \{AB, CD\}
$$

**Proposizione 2 (conservazione dei luoghi)** Se si trasforma un luogo $$\Gamma_K$$ con un'inversione, si ottiene un altro luogo $$\Gamma_K'$$.

...........
continua da pagina 9

### Soluzione inversiva

Se inverto due cerchi tangenti rispetto ad una circonferenza gamma con centro O nel punto di tangenza, ottendo due rette parallele

<!-- figura -->

Siano ora tre cerchi tangenti a due a due. Si scelga uno dei vertici del triangolo curvilineo come centro di una circonferenza gamma e si inverta. Si otterrà un cerchio tangente a due rette parallele.

<!-- figura -->

Ma in quest'ultima figura trovare le due soluzioni del PdA è più facile.
Data l'immagine dei tre cerchi,

<!-- figura -->

i due cerchi soluzione sono anch'essi tangenti alle due rette parallele e, applicando di nuovo la stessa inversione,

<!-- figura -->

### Soluzione classica

### La retta proiettiva complessa

#### Cerchi reali e rette

#### Trasformazioni di Möbius sulla sfera

#### Soluzione proiettiva

## Modello dello spazio iperbolico

### Classificazione delle matrici hermitiane

### Estensione di Poincarè

### Altri modelli dello spazio iperbolico

## Iterazione

### Iterazione naturale

### Anatema: definizione costruttiva

### Proprietà dell'Anatema

### Un altro Anatema

## Frazioni continue complesse e orosfere nello Spazio Iperbolico

{% include lib/mathjax.html %}

