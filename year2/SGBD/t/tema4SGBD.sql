DECLARE 
    TYPE vector IS VARRAY(20) OF NUMBER(6);
    t   vector;
    var NUMBER(8,2) := 0;
BEGIN 
    SELECT employee_id BULK COLLECT INTO t
    FROM (SELECT employee_id
          FROM employees
        WHERE commission_pct IS NULL
        ORDER BY salary)
    WHERE ROWNUM <6;
    
    FOR i in 1..5 LOOP
        SELECT salary INTO var
        FROM employees 
        WHERE employee_id=t(i);
        DBMS_OUTPUT.PUT_LINE(var|| ' ');
    END LOOP;
    DBMS_OUTPUT.NEW_LINE;
    FOR i in 1..5 LOOP
        SELECT salary INTO var
        FROM employees 
        WHERE employee_id=t(i);
        var:=var+(5/100)*var;
        DBMS_OUTPUT.PUT_LINE(var|| ' ');
    END LOOP;
END; 