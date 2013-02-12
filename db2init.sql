
CREATE DISTINCT TYPE LongName AS LONG VARGRAPHIC ;



CREATE DISTINCT TYPE Units AS VARCHAR(5)  WITH COMPARISONS;



CREATE TABLE Application_timetable
(
	id_Timetable          INTEGER  NOT NULL ,
	Date                  DATE  NOT NULL ,
	Quantity              INTEGER  NOT NULL ,
	id_Staff              INTEGER  NOT NULL ,
	id_Patient            INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKApplication_timetable ON Application_timetable
(
	id_Timetable          ASC
)
	;



ALTER TABLE Application_timetable
	ADD CONSTRAINT XPKApplication_timetable  PRIMARY KEY (id_Timetable);



CREATE TABLE Condition
(
	id_Condition          INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL 
);



CREATE UNIQUE INDEX XPKCondition ON Condition
(
	id_Condition          ASC
)
	;



ALTER TABLE Condition
	ADD CONSTRAINT XPKCondition  PRIMARY KEY (id_Condition);



CREATE TABLE Custom
(
	id_Institution        INTEGER  NOT NULL ,
	id_Supplier           INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKCustom ON Custom
(
	id_Institution        ASC,
	id_Supplier           ASC
)
	;



ALTER TABLE Custom
	ADD CONSTRAINT XPKCustom  PRIMARY KEY (id_Institution,id_Supplier);



CREATE TABLE Cycle_of_patient
(
	id_Cycle              INTEGER  NOT NULL ,
	Date_of_admission     DATE  NOT NULL ,
	Date_of_leaving       DATE  NOT NULL ,
	id_Patient            INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKCycle_of_patient ON Cycle_of_patient
(
	id_Cycle              ASC
)
	;



ALTER TABLE Cycle_of_patient
	ADD CONSTRAINT XPKCycle_of_patient  PRIMARY KEY (id_Cycle);



CREATE TABLE Equipment
(
	id_Equipment          INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL ,
	Quantity              INTEGER  NOT NULL ,
	id_Condition          INTEGER  NOT NULL ,
	id_Supplier           INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKEquipment ON Equipment
(
	id_Equipment          ASC
)
	;



ALTER TABLE Equipment
	ADD CONSTRAINT XPKEquipment  PRIMARY KEY (id_Equipment);



CREATE TABLE Given_medicine
(
	id_Medicine           INTEGER  NOT NULL ,
	id_Timetable          INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKGiven_medicine ON Given_medicine
(
	id_Medicine           ASC,
	id_Timetable          ASC
)
	;



ALTER TABLE Given_medicine
	ADD CONSTRAINT XPKGiven_medicine  PRIMARY KEY (id_Medicine,id_Timetable);



CREATE TABLE Illness
(
	id_Illness            INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL 
);



CREATE UNIQUE INDEX XPKIllness ON Illness
(
	id_Illness            ASC
)
	;



ALTER TABLE Illness
	ADD CONSTRAINT XPKIllness  PRIMARY KEY (id_Illness);



CREATE TABLE Illness_in_history
(
	id_History            INTEGER  NOT NULL ,
	id_Illness            INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKIllness_in_history ON Illness_in_history
(
	id_History            ASC,
	id_Illness            ASC
)
	;



ALTER TABLE Illness_in_history
	ADD CONSTRAINT XPKIllness_in_history  PRIMARY KEY (id_History,id_Illness);



CREATE TABLE Leave
(
	id_Leave              INTEGER  NOT NULL ,
	Term                  INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL 
);



CREATE UNIQUE INDEX XPKLeave ON Leave
(
	id_Leave              ASC
)
	;



ALTER TABLE Leave
	ADD CONSTRAINT XPKLeave  PRIMARY KEY (id_Leave);



CREATE TABLE Medical_history
(
	id_History            INTEGER  NOT NULL ,
	id_Staff              INTEGER  NOT NULL ,
	id_Cycle              INTEGER  NOT NULL ,
	id_Traced_operation   INTEGER ,
	id_Traced_survey      INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKMedical_history ON Medical_history
(
	id_History            ASC
)
	;



ALTER TABLE Medical_history
	ADD CONSTRAINT XPKMedical_history  PRIMARY KEY (id_History);



CREATE TABLE Medical_institution
(
	id_Institution        INTEGER  NOT NULL ,
	Address               LongName  NOT NULL ,
	Phone_number_of_pigeon_hole  INTEGER  NOT NULL ,
	Licence_number        VARCHAR(20)  NOT NULL ,
	Name                  LongName  NOT NULL 
);



CREATE UNIQUE INDEX XPKMedical_institution ON Medical_institution
(
	id_Institution        ASC
)
	;



ALTER TABLE Medical_institution
	ADD CONSTRAINT XPKMedical_institution  PRIMARY KEY (id_Institution);



CREATE TABLE Medicine
(
	id_Medicine           INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL ,
	Quantity              INTEGER  NOT NULL ,
	id_Unit               INTEGER  NOT NULL ,
	id_Condition          INTEGER  NOT NULL ,
	id_Supplier           INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKMedicine ON Medicine
(
	id_Medicine           ASC
)
	;



ALTER TABLE Medicine
	ADD CONSTRAINT XPKMedicine  PRIMARY KEY (id_Medicine);



CREATE TABLE Operation
(
	id_Operation          INTEGER  NOT NULL ,
	Date                  DATE  NOT NULL ,
	id_Operation_type     INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKOperation ON Operation
(
	id_Operation          ASC
)
	;



ALTER TABLE Operation
	ADD CONSTRAINT XPKOperation  PRIMARY KEY (id_Operation);



CREATE TABLE Operation_type
(
	id_Operation_type     INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL 
);



CREATE UNIQUE INDEX XPKOperation_type ON Operation_type
(
	id_Operation_type     ASC
)
	;



ALTER TABLE Operation_type
	ADD CONSTRAINT XPKOperation_type  PRIMARY KEY (id_Operation_type);



CREATE TABLE Patient
(
	id_Patient            INTEGER  NOT NULL ,
	Last_name             VARCHAR(20)  NOT NULL ,
	First_name            VARCHAR(20)  NOT NULL ,
	Fathers_name          VARCHAR(20)  NOT NULL ,
	Date_of_birth         DATE  NOT NULL ,
	id_Institution        INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKPatient ON Patient
(
	id_Patient            ASC
)
	;



ALTER TABLE Patient
	ADD CONSTRAINT XPKPatient  PRIMARY KEY (id_Patient);



CREATE TABLE Patient_service
(
	id_Patient            INTEGER  NOT NULL ,
	id_Staff              INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKPatient_service ON Patient_service
(
	id_Patient            ASC,
	id_Staff              ASC
)
	;



ALTER TABLE Patient_service
	ADD CONSTRAINT XPKPatient_service  PRIMARY KEY (id_Patient,id_Staff);



CREATE TABLE Staff
(
	id_Staff              INTEGER  NOT NULL ,
	Last_name             VARCHAR(20)  NOT NULL ,
	First_name            VARCHAR(20)  NOT NULL ,
	Fathers_name          VARCHAR(20)  NOT NULL ,
	MDorS                 VARCHAR(20)  NOT NULL ,
	Post                  VARCHAR(20)  NOT NULL ,
	Salary                INTEGER  NOT NULL ,
	Num_of_diploma        VARCHAR(20) ,
	Academic_degree       VARCHAR(20) ,
	id_Institution        INTEGER  NOT NULL ,
	id_Leave              INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKStaff ON Staff
(
	id_Staff              ASC
)
	;



ALTER TABLE Staff
	ADD CONSTRAINT XPKStaff  PRIMARY KEY (id_Staff);



CREATE TABLE Supplier
(
	id_Supplier           INTEGER  NOT NULL ,
	Date_of_making_of_contract  DATE  NOT NULL ,
	Name                  LongName  NOT NULL 
);



CREATE UNIQUE INDEX XPKSupplier ON Supplier
(
	id_Supplier           ASC
)
	;



ALTER TABLE Supplier
	ADD CONSTRAINT XPKSupplier  PRIMARY KEY (id_Supplier);



CREATE TABLE Survey
(
	id_Survey             INTEGER  NOT NULL ,
	Date                  DATE  NOT NULL ,
	id_Equipment          INTEGER  NOT NULL ,
	id_Survey_type        INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKSurvey ON Survey
(
	id_Survey             ASC
)
	;



ALTER TABLE Survey
	ADD CONSTRAINT XPKSurvey  PRIMARY KEY (id_Survey);



CREATE TABLE Survey_of_patient
(
	id_Patient            INTEGER  NOT NULL ,
	id_Survey             INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKSurvey_of_patient ON Survey_of_patient
(
	id_Patient            ASC,
	id_Survey             ASC
)
	;



ALTER TABLE Survey_of_patient
	ADD CONSTRAINT XPKSurvey_of_patient  PRIMARY KEY (id_Patient,id_Survey);



CREATE TABLE Survey_type
(
	id_Survey_type        INTEGER  NOT NULL ,
	Name                  VARCHAR(20)  NOT NULL 
);



CREATE UNIQUE INDEX XPKSurvey_type ON Survey_type
(
	id_Survey_type        ASC
)
	;



ALTER TABLE Survey_type
	ADD CONSTRAINT XPKSurvey_type  PRIMARY KEY (id_Survey_type);



CREATE TABLE Traced_operation
(
	id_Traced_operation   INTEGER  NOT NULL ,
	id_Staff              INTEGER  NOT NULL ,
	id_Operation          INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKTraced_operation ON Traced_operation
(
	id_Traced_operation   ASC
)
	;



ALTER TABLE Traced_operation
	ADD CONSTRAINT XPKTraced_operation  PRIMARY KEY (id_Traced_operation);



CREATE UNIQUE INDEX XAK1Traced_operation ON Traced_operation
(
	id_Staff              ASC,
	id_Operation          ASC
)
	;



CREATE TABLE Traced_survey
(
	id_Traced_survey      INTEGER  NOT NULL ,
	id_Survey             INTEGER  NOT NULL ,
	id_Staff              INTEGER  NOT NULL 
);



CREATE UNIQUE INDEX XPKTraced_survey ON Traced_survey
(
	id_Traced_survey      ASC
)
	;



ALTER TABLE Traced_survey
	ADD CONSTRAINT XPKTraced_survey  PRIMARY KEY (id_Traced_survey);



CREATE UNIQUE INDEX XAK1Traced_survey ON Traced_survey
(
	id_Staff              ASC,
	id_Survey             ASC
)
	;



CREATE TABLE Unit
(
	id_Unit               INTEGER  NOT NULL ,
	Name                  Units  NOT NULL 
);



CREATE UNIQUE INDEX XPKUnit ON Unit
(
	id_Unit               ASC
)
	;



ALTER TABLE Unit
	ADD CONSTRAINT XPKUnit  PRIMARY KEY (id_Unit);



ALTER TABLE Given_medicine
ADD CONSTRAINT R_33  FOREIGN KEY (id_Timetable) REFERENCES Application_timetable (id_Timetable)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Equipment
ADD CONSTRAINT R_28  FOREIGN KEY (id_Condition) REFERENCES Condition (id_Condition)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Medicine
ADD CONSTRAINT R_29  FOREIGN KEY (id_Condition) REFERENCES Condition (id_Condition)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Medical_history
ADD CONSTRAINT R_10  FOREIGN KEY (id_Cycle) REFERENCES Cycle_of_patient (id_Cycle)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Survey
ADD CONSTRAINT R_20  FOREIGN KEY (id_Equipment) REFERENCES Equipment (id_Equipment)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Illness_in_history
ADD CONSTRAINT R_8  FOREIGN KEY (id_Illness) REFERENCES Illness (id_Illness)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Staff
ADD CONSTRAINT R_13  FOREIGN KEY (id_Leave) REFERENCES Leave (id_Leave)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Staff
ADD CONSTRAINT R_14  FOREIGN KEY (id_Institution) REFERENCES Medical_institution (id_Institution)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Patient
ADD CONSTRAINT R_21  FOREIGN KEY (id_Institution) REFERENCES Medical_institution (id_Institution)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Traced_operation
ADD CONSTRAINT R_3  FOREIGN KEY (id_Operation) REFERENCES Operation (id_Operation)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Patient_service
ADD CONSTRAINT R_7  FOREIGN KEY (id_Patient) REFERENCES Patient (id_Patient)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Survey_of_patient
ADD CONSTRAINT R_17  FOREIGN KEY (id_Patient) REFERENCES Patient (id_Patient)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Traced_operation
ADD CONSTRAINT R_2  FOREIGN KEY (id_Staff) REFERENCES Staff (id_Staff)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Traced_survey
ADD CONSTRAINT R_4  FOREIGN KEY (id_Staff) REFERENCES Staff (id_Staff)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Traced_survey
ADD CONSTRAINT R_5  FOREIGN KEY (id_Survey) REFERENCES Survey (id_Survey)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Survey_of_patient
ADD CONSTRAINT R_18  FOREIGN KEY (id_Survey) REFERENCES Survey (id_Survey)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Application_timetable
	ADD CONSTRAINT R_15  FOREIGN KEY (id_Staff) REFERENCES Staff (id_Staff)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;




ALTER TABLE Application_timetable
	ADD CONSTRAINT R_34  FOREIGN KEY (id_Patient) REFERENCES Patient (id_Patient)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Custom
	ADD CONSTRAINT R_22  FOREIGN KEY (id_Institution) REFERENCES Medical_institution (id_Institution)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;




ALTER TABLE Custom
	ADD CONSTRAINT R_24  FOREIGN KEY (id_Supplier) REFERENCES Supplier (id_Supplier)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Cycle_of_patient
	ADD CONSTRAINT R_16  FOREIGN KEY (id_Patient) REFERENCES Patient (id_Patient)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Equipment
	ADD CONSTRAINT R_25  FOREIGN KEY (id_Supplier) REFERENCES Supplier (id_Supplier)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Given_medicine
	ADD CONSTRAINT R_32  FOREIGN KEY (id_Medicine) REFERENCES Medicine (id_Medicine)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Illness_in_history
	ADD CONSTRAINT R_9  FOREIGN KEY (id_History) REFERENCES Medical_history (id_History)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Medical_history
	ADD CONSTRAINT R_11  FOREIGN KEY (id_Traced_operation) REFERENCES Traced_operation (id_Traced_operation)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;




ALTER TABLE Medical_history
	ADD CONSTRAINT R_12  FOREIGN KEY (id_Staff) REFERENCES Staff (id_Staff)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;




ALTER TABLE Medical_history
	ADD CONSTRAINT R_36  FOREIGN KEY (id_Traced_survey) REFERENCES Traced_survey (id_Traced_survey)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Medicine
	ADD CONSTRAINT R_27  FOREIGN KEY (id_Supplier) REFERENCES Supplier (id_Supplier)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;




ALTER TABLE Medicine
	ADD CONSTRAINT R_31  FOREIGN KEY (id_Unit) REFERENCES Unit (id_Unit)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Operation
	ADD CONSTRAINT R_1  FOREIGN KEY (id_Operation_type) REFERENCES Operation_type (id_Operation_type)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Patient_service
	ADD CONSTRAINT R_6  FOREIGN KEY (id_Staff) REFERENCES Staff (id_Staff)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;



ALTER TABLE Survey
	ADD CONSTRAINT R_19  FOREIGN KEY (id_Survey_type) REFERENCES Survey_type (id_Survey_type)
		ON DELETE NO ACTION
		ON UPDATE NO ACTION;


