CREATE FUNCTION total_patients (id_med_in INT) RETURNS INT LANGUAGE SQL READS SQL DATA NO EXTERNAL ACTION NOT DETERMINISTIC RETURN SELECT count(*) FROM DB2ADMIN.Patient m WHERE (m.id_Institution = id_med_in)

CREATE FUNCTION total_costs (id_med_in INT) RETURNS INT LANGUAGE SQL READS SQL DATA NO EXTERNAL ACTION NOT DETERMINISTIC RETURN SELECT sum(s.Salary) FROM DB2ADMIN.Staff s WHERE (s.id_Institution = id_med_in)

CREATE FUNCTION illnesses(pat_id INT) RETURNS TABLE(Illness VARCHAR(20), Date_of_admission DATE, Date_of_leaving Date) LANGUAGE SQL READS SQL DATA NO EXTERNAL ACTION NOT DETERMINISTIC RETURN SELECT l.Name, c.Date_of_admission, c.Date_of_leaving FROM DB2ADMIN.Cycle_of_patient c, DB2ADMIN.Medical_history m, DB2ADMIN.Illness_in_history ih, DB2ADMIN.Illness l WHERE c.id_Patient = pat_id AND m.id_Cycle = c.id_Cycle AND m.id_History = ih.id_history AND l.id_Illness = l.id_Illness

CREATE PROCEDURE increase_salary(IN val INT) LANGUAGE SQL MODIFIES SQL DATA NO EXTERNAL ACTION BEGIN UPDATE DB2ADMIN.Staff SET Salary = Salary + val; END 

CREATE PROCEDURE remove_old_contracts() LANGUAGE SQL MODIFIES SQL DATA NO EXTERNAL ACTION BEGIN DELETE FROM DB2ADMIN.Supplier s WHERE (current_date - s.Date_of_making_of_contract) > 360; END

CREATE PROCEDURE remove_empty_medicine() LANGUAGE SQL MODIFIES SQL DATA NO EXTERNAL ACTION BEGIN DELETE FROM DB2ADMIN.Medicine m WHERE m.Quantity = 0; END