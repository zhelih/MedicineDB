CREATE ROLE operator;

GRANT ALL ON TABLE MEDICAL_INSTITUTION TO ROLE operator;
GRANT ALL ON TABLE STAFF TO ROLE operator;
GRANT ALL ON TABLE CYCLE_OF_PATIENT TO ROLE operator;
GRANT ALL ON TABLE MEDICAL_HISTORY TO ROLE operator;
GRANT ALL ON TABLE PATIENT TO ROLE operator;
GRANT ALL ON TABLE APPLICATION_TIMETABLE TO ROLE operator;
GRANT ALL ON TABLE SURVEY TO ROLE operator;
GRANT SELECT ON TABLE OPERATION_TYPE TO ROLE operator;
GRANT SELECT ON TABLE PATIENT_SERVICE TO ROLE operator;
GRANT SELECT ON TABLE SURVEY_OF_PATIENT TO ROLE operator;
GRANT SELECT ON TABLE SURVEY_TYPE TO ROLE operator;
GRANT SELECT ON TABLE TRACED_SURVEY TO ROLE operator;
GRANT SELECT ON TABLE UNIT TO ROLE operator;
GRANT SELECT ON TABLE OPERATION TO ROLE operator;
GRANT SELECT ON TABLE EQUIPMENT TO ROLE operator;
GRANT SELECT ON TABLE LEAVE TO ROLE operator;
GRANT SELECT ON TABLE ILLNESS_IN_HISTORY TO ROLE operator;
GRANT SELECT ON TABLE MEDICINE TO ROLE operator;
GRANT SELECT ON TABLE CUSTOM TO ROLE operator;
GRANT SELECT ON TABLE CONDITION TO ROLE operator;
GRANT SELECT ON TABLE SUPPLIER TO ROLE operator;
GRANT SELECT ON TABLE ILLNESS TO ROLE operator;
GRANT SELECT ON TABLE GIVEN_MEDICINE TO ROLE operator;

GRANT ROLE operator TO USER operator;