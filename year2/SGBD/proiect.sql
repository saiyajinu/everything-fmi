CREATE OR REPLACE PACKAGE cerinta13
AS
    PROCEDURE cerinta6(nume Sponsor.nume%TYPE, nume_doi Sponsor.nume%TYPE);
    PROCEDURE cerinta7;
    FUNCTION cerinta8(id NUMBER) RETURN NUMBER;
    PROCEDURE cerinta9(id NUMBER);
END cerinta13;
/

CREATE OR REPLACE PACKAGE BODY cerinta13
AS
    PROCEDURE cerinta6 (nume Sponsor.nume%TYPE, nume_doi Sponsor.nume%TYPE) AS
        TYPE tabel_indexat IS TABLE OF Echipa%ROWTYPE INDEX BY PLS_INTEGER;
        t tabel_indexat;
        TYPE tabel_imbricat IS TABLE OF VARCHAR2(50);
        y tabel_imbricat;
        TYPE vector IS VARRAY(20) OF NUMBER;
        u vector:= vector();
        
    BEGIN
        SELECT E.*
        BULK COLLECT INTO t
        FROM ECHIPA E
        JOIN ECHIPA_SPONSOR ES ON E.ID_ECHIPA = ES.ID_ECHIPA
        JOIN SPONSOR S ON ES.ID_SPONSOR = S.ID_SPONSOR
        WHERE S.NUME = cerinta6.nume;
        u.extend;
        u(1) := t.COUNT;
        FOR i IN 1..t.COUNT LOOP
            DBMS_OUTPUT.PUT_LINE(t(i).nume || ', ' || t(i).id_echipa);
        END LOOP;
        DBMS_OUTPUT.PUT_LINE('');
        
        SELECT E.nume
        BULK COLLECT INTO y
        FROM ECHIPA E
        JOIN ECHIPA_SPONSOR ES ON E.ID_ECHIPA = ES.ID_ECHIPA
        JOIN SPONSOR S ON ES.ID_SPONSOR = S.ID_SPONSOR
        WHERE S.NUME = cerinta6.nume_doi;
        u.extend;
        u(2) := y.COUNT;
        FOR i IN 1..y.COUNT LOOP
            DBMS_OUTPUT.PUT_LINE(y(i));
        END LOOP;
        DBMS_OUTPUT.PUT_LINE('');
        DBMS_OUTPUT.PUT_LINE(u(1) || ', ' || u(2));   
    END;
    
    PROCEDURE cerinta7 AS
    CURSOR c1 IS
        SELECT j.id_jucator, j.nume, j.id_echipa
        FROM JUCATOR j;
    CURSOR c2 (v_id_echipa ECHIPA.id_echipa%TYPE) IS
        SELECT COUNT(*)
        FROM ECHIPA e
        JOIN JUCATOR j ON e.id_echipa = j.id_echipa
        WHERE e.id_echipa = v_id_echipa;
    
    v_id_jucator JUCATOR.id_jucator%TYPE;
    v_nume_jucator JUCATOR.nume%TYPE;
    v_id_echipa ECHIPA.id_echipa%TYPE;
    v_total_jucatori NUMBER;

    BEGIN
        OPEN c1;
        LOOP
            FETCH c1 INTO v_id_jucator, v_nume_jucator, v_id_echipa;
            EXIT WHEN c1%NOTFOUND;
            DBMS_OUTPUT.PUT_LINE(v_id_jucator || ', ' || v_nume_jucator);
            OPEN c2(v_id_echipa);
            FETCH c2 INTO v_total_jucatori;
            DBMS_OUTPUT.PUT_LINE('are ' || (v_total_jucatori - 1) || ' coechipier(i).');
            CLOSE c2;
        END LOOP;
        CLOSE c1;
    END;
    
    FUNCTION cerinta8(id NUMBER) RETURN NUMBER IS 
    nr_turnee NUMBER;
    aux NUMBER;
    nume_com COMENTATOR.nume%TYPE;
    v_comentator COMENTATOR%ROWTYPE;
    WRONG_ID EXCEPTION;
    NO_TOURNAMENTS EXCEPTION;

BEGIN
    SELECT COUNT(*) into aux
    FROM comentator
    WHERE id_comentator = id;
    
    IF aux = 0 THEN
        RAISE WRONG_ID;
    END IF;
        
    SELECT COUNT(DISTINCT t.id_turneu) into nr_turnee
    FROM MECI m
    JOIN COMENTATOR c on m.id_comentator = c.id_comentator
    JOIN TURNEU t on m.id_turneu = t.id_turneu
    WHERE m.id_comentator = id;
    
    
    IF nr_turnee = 0 THEN
        RAISE NO_TOURNAMENTS;
    END IF;
    
    RETURN nr_turnee;
    
    EXCEPTION
        WHEN WRONG_ID THEN
            DBMS_OUTPUT.PUT_LINE('Niciun comentator nu are acest id');
            RETURN -1;
        WHEN NO_TOURNAMENTS THEN
            DBMS_OUTPUT.PUT_LINE('Comentatorul nu a fost la niciun turneu');
            RETURN -1;
    END;

    PROCEDURE cerinta9(id NUMBER)
AS
    TYPE vector_id_echipe IS VARRAY(2) OF NUMBER;
    u vector_id_echipe:= vector_id_echipe();
    v_sponsor VARCHAR2(50);
    NO_DATA_FOUND EXCEPTION;
    TOO_MANY_ROWS EXCEPTION;
    aux NUMBER;
    WRONG_ID EXCEPTION;
    
    
BEGIN
    SELECT COUNT(*) into aux
    FROM meci
    WHERE id_meci = id;
    
    IF aux = 0 THEN
        RAISE WRONG_ID;
    END IF;


    FOR rec IN (
        SELECT DISTINCT j.id_echipa
        FROM meci m 
        JOIN jucator_meci jm ON m.id_meci = jm.id_meci
        JOIN jucator j ON jm.id_jucator1 = j.id_jucator OR jm.id_jucator2 = j.id_jucator
        WHERE m.id_meci = id
    ) LOOP
        u.EXTEND;
        u(u.LAST) := rec.id_echipa;
    END LOOP;
    IF u(u.LAST) IS null THEN
        RAISE NO_DATA_FOUND;
        RETURN;
    END IF;
    IF u.COUNT > 2 THEN
        RAISE TOO_MANY_ROWS;
        RETURN;
    END IF;
    
    DBMS_OUTPUT.PUT_LINE(u.LAST);
    DBMS_OUTPUT.PUT_LINE('Pentru meciul ' || id);
    FOR val in 1..u.COUNT LOOP
        IF u.COUNT = 1 THEN
            DBMS_OUTPUT.PUT_LINE('Ambii jucatori fac parte din aceeasi organizatie (' || u(1) || ')');
            DBMS_OUTPUT.PUT_LINE('Sponsorii prezenti sunt:');
        ELSE
            DBMS_OUTPUT.PUT_LINE('Echipa jucatorului ' || val || ' (' || u(1) || ') are sponsorii:');
        END IF;
        FOR rez IN (SELECT s.nume
              FROM sponsor s
              JOIN echipa_sponsor es ON es.id_sponsor = s.id_sponsor
              JOIN echipa e ON e.id_Echipa = es.id_echipa AND e.id_echipa = u(val))
        LOOP
            v_sponsor := rez.nume;
            DBMS_OUTPUT.PUT_LINE(v_sponsor);
        END LOOP;
    END LOOP;
    
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('no data found');
        WHEN TOO_MANY_ROWS THEN
            DBMS_OUTPUT.PUT_LINE('too many rows');
        WHEN WRONG_ID THEN
            DBMS_OUTPUT.PUT_LINE('wrong id');
    
    END;

    
END cerinta13;
/

    