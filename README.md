# SDA

### Cum funcționează Kruskal?

- Sortează muchiile:
  
Se sortează toate muchiile grafului după costul lor (de la cele mai mici la cele mai mari).

- Selectează muchii pentru MST:

Algoritmul selectează fiecare muchie, în ordine crescătoare a costurilor, și o adaugă în MST doar dacă aceasta nu formează un ciclu.

- Verifică ciclurile:

Pentru a evita formarea unui ciclu, Kruskal utilizează un mecanism de uniune a componentelor conexe. Se păstrează un set de componente disjuncte, fiecare nod fiind parte dintr-o componentă. Dacă două noduri sunt deja în aceeași componentă, adăugarea muchiei ar crea un ciclu, așa că nu se adaugă.

- Oprește când MST este complet:

Algoritmul continuă să aleagă muchii până când arborele de acoperire minimă conține exact n-1 muchii (unde n este numărul de noduri din graf). La acest punct, MST-ul este complet și se oprește.


### Cum funcționează Prim?

- Începe de la un nod arbitrari:

Se alege un nod de început (orice nod din graf), care devine parte a MST-ului.

- Se selectează muchia cu cost minim:

Se caută muchia de cost minim care leagă un nod din MST de unul care nu face încă parte din MST. Această muchie este adăugată la MST.

- Actualizează setul de noduri:

După adăugarea nodului în MST, se actualizează lista de muchii și noduri posibile, continuând căutarea muchiei de cost minim care leagă un nod din MST de un nod exterior MST-ului.

- Continuă până când toate nodurile sunt incluse:

Algoritmul continuă să adauge noduri la MST până când toate nodurile din graf sunt incluse, adică MST-ul conține exact n-1 muchii.
