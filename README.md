# SDA
### ***Ford-Fulkerson***
este un algoritm care rezolva problema fluxului maxim intr-un graf, adica gaseste cantitatea maxima de flux care poate circula de la sursa la destinatie, avand in vedere ca fiecare muchie are o capacitate limita.

Cum functioneaza:

- Gasim o cale de la sursa la destinatie folosind BFS (cautare in latime).
- Verificam capacitatea minima pe acea cale (care este limita fluxului pe respectiva cale).
- Adaugam fluxul minim pe acea cale si actualizam capacitatile muchiilor.
- Repetam pasii pana nu mai gasim o cale valida cu capacitate pozitiva.
- Fluxul maxim este suma fluxurilor adaugate pe fiecare cale valida.
- In esenta, algoritmul continua sa adauge flux in retea pe cai disponibile pana cand nu mai poate, iar rezultatul final este fluxul maxim.
