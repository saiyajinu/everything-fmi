GRANT CREATE TABLE TO new_user;
grant dba to new_user;
SELECT * FROM USER_SYS_PRIVS WHERE PRIVILEGE = 'CREATE TABLE';
SELECT * FROM USER_ROLE_PRIVS;


CREATE TABLE NEW_USER.MECI (
    id_meci NUMBER PRIMARY KEY,
    data DATE,
    duratie NUMBER,
    etapa VARCHAR2(50),
    id_comentator NUMBER,
    id_turneu NUMBER,
    FOREIGN KEY (id_comentator) REFERENCES COMENTATOR(id_comentator)
);


CREATE OR REPLACE TRIGGER cerinta10
BEFORE INSERT OR UPDATE OR DELETE ON MECI
DECLARE
    ora CONSTANT NUMBER := 18;
BEGIN
    IF TO_NUMBER(TO_CHAR(SYSDATE, 'HH24')) >= ora_limita THEN
        RAISE_APPLICATION_ERROR(-20001, 'Operatiuni interzise dupa ora ' || ora || ':00');
    END IF;
END;
/
