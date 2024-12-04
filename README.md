# SDA
### ***Ford-Fulkerson*** - complexitate O(E*fluxul maxim)
este un algoritm care rezolva problema fluxului maxim intr-un graf, adica gaseste cantitatea maxima de flux care poate circula de la sursa la destinatie, avand in vedere ca fiecare muchie are o capacitate limita.

Cum functioneaza:

- Gasim o cale de la sursa la destinatie folosind BFS (cautare in latime).
- Verificam capacitatea minima pe acea cale (care este limita fluxului pe respectiva cale).
- Adaugam fluxul minim pe acea cale si actualizam capacitatile muchiilor.
- Repetam pasii pana nu mai gasim o cale valida cu capacitate pozitiva.
- Fluxul maxim este suma fluxurilor adaugate pe fiecare cale valida.
- In esenta, algoritmul continua sa adauge flux in retea pe cai disponibile pana cand nu mai poate, iar rezultatul final este fluxul maxim.

### ***Algoritmul KMP (Knuth-Morris-Pratt)*** - complexitate O(n + m), unde n este lungimea textului și m este lungimea pattern-ului.

Imaginați-vă că aveți o foaie de hârtie pe care scrie un text și o altă foaie pe care scrie un pattern (un șir de cuvinte pe care îl căutați în text). Acum, să spunem că vreți să găsiți unde se află pattern-ul în text. În loc să începeți să comparați fiecare literă din text cu fiecare literă din pattern de la început (ceea ce ar lua mult timp), algoritmul KMP ne ajută să facem acest lucru mai rapid.

Pașii algoritmului KMP:

1. Preprocesarea pattern-ului:

- Înainte de a începe căutarea, creăm un vector LPS (Longest Prefix Suffix). Acesta este ca un harta secretă care ne spune câte caractere din pattern s-au potrivit deja la început, pentru a nu mai verifica aceleași caractere din nou.
- De exemplu, dacă avem pattern-ul "aaba", vectorul LPS ne va spune:

- Că "a" se potrivește cu "a" la început (deci, LPS[0] = 0). Că "aa" se potrivește cu "aa" (LPS[1] = 1) și așa mai departe.

2. Căutarea efectivă:

- După ce avem harta secretă (LPS), începe căutarea efectivă. Comparați textul cu pattern-ul.
- Dacă găsiți o nepotrivire, în loc să începeți de la capăt cu pattern-ul, folosiți harta secretă (LPS) ca să săriți direct la următoarea poziție posibilă unde s-ar putea potrivi.

3. De ce este mai rapid:
- KMP economisește timp pentru că nu compară aceleași caractere de două ori. Dacă un fragment din pattern a fost deja verificat și s-a potrivit, algoritmul știe să sară peste acea parte și să meargă mai departe, folosind informațiile din LPS.
