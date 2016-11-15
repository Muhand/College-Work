SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Create mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`PERSON`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`PERSON` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(100) NOT NULL,
  `age` INT NOT NULL,
  `gender` CHAR(1) NOT NULL,
  PRIMARY KEY (`id`, `name`, `gender`, `age`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`SUBJECT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`SUBJECT` (
  `subject_number` INT NOT NULL AUTO_INCREMENT,
  `subject_name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`subject_number`, `subject_name`),
  UNIQUE INDEX `subject_number_UNIQUE` (`subject_number` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`SEAT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`SEAT` (
  `seat_num` INT NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`seat_num`),
  UNIQUE INDEX `seat_num_UNIQUE` (`seat_num` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`STUDENT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`STUDENT` (
  `student_address` VARCHAR(255) NOT NULL,
  `student_id` INT NOT NULL AUTO_INCREMENT,
  `PERSON_id` INT NOT NULL,
  `PERSON_name` VARCHAR(100) NOT NULL,
  `PERSON_gender` CHAR(1) NOT NULL,
  `PERSON_age` INT NOT NULL,
  `SUBJECT_subject_number` INT NOT NULL,
  `SUBJECT_subject_name` VARCHAR(45) NOT NULL,
  `SEAT_seat_num` INT NOT NULL,
  PRIMARY KEY (`student_id`, `PERSON_id`, `PERSON_name`, `PERSON_gender`, `PERSON_age`, `SUBJECT_subject_number`, `SUBJECT_subject_name`, `SEAT_seat_num`),
  UNIQUE INDEX `student_id_UNIQUE` (`student_id` ASC),
  INDEX `fk_STUDENT_PERSON1_idx` (`PERSON_id` ASC, `PERSON_name` ASC, `PERSON_gender` ASC, `PERSON_age` ASC),
  INDEX `fk_STUDENT_SUBJECT1_idx` (`SUBJECT_subject_number` ASC, `SUBJECT_subject_name` ASC),
  INDEX `fk_STUDENT_SEAT1_idx` (`SEAT_seat_num` ASC),
  CONSTRAINT `fk_STUDENT_PERSON1`
    FOREIGN KEY (`PERSON_id` , `PERSON_name` , `PERSON_gender` , `PERSON_age`)
    REFERENCES `mydb`.`PERSON` (`id` , `name` , `gender` , `age`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_STUDENT_SUBJECT1`
    FOREIGN KEY (`SUBJECT_subject_number` , `SUBJECT_subject_name`)
    REFERENCES `mydb`.`SUBJECT` (`subject_number` , `subject_name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_STUDENT_SEAT1`
    FOREIGN KEY (`SEAT_seat_num`)
    REFERENCES `mydb`.`SEAT` (`seat_num`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`TEACHER`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`TEACHER` (
  `teacher_id` INT NOT NULL AUTO_INCREMENT,
  `PERSON_id` INT NOT NULL,
  `PERSON_name` VARCHAR(100) NOT NULL,
  `PERSON_gender` CHAR(1) NOT NULL,
  `PERSON_age` INT NOT NULL,
  PRIMARY KEY (`teacher_id`, `PERSON_id`, `PERSON_name`, `PERSON_gender`, `PERSON_age`),
  UNIQUE INDEX `teacher_id_UNIQUE` (`teacher_id` ASC),
  INDEX `fk_TEACHER_PERSON1_idx` (`PERSON_id` ASC, `PERSON_name` ASC, `PERSON_gender` ASC, `PERSON_age` ASC),
  CONSTRAINT `fk_TEACHER_PERSON1`
    FOREIGN KEY (`PERSON_id` , `PERSON_name` , `PERSON_gender` , `PERSON_age`)
    REFERENCES `mydb`.`PERSON` (`id` , `name` , `gender` , `age`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`TEACHER_has_SUBJECT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`TEACHER_has_SUBJECT` (
  `TEACHER_teacher_id` INT NOT NULL,
  `TEACHER_PERSON_id` INT NOT NULL,
  `TEACHER_PERSON_name` VARCHAR(100) NOT NULL,
  `TEACHER_PERSON_gender` CHAR(1) NOT NULL,
  `TEACHER_PERSON_age` INT NOT NULL,
  `SUBJECT_subject_number` INT NOT NULL,
  `SUBJECT_subject_name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`TEACHER_teacher_id`, `TEACHER_PERSON_id`, `TEACHER_PERSON_name`, `TEACHER_PERSON_gender`, `TEACHER_PERSON_age`, `SUBJECT_subject_number`, `SUBJECT_subject_name`),
  INDEX `fk_TEACHER_has_SUBJECT_SUBJECT1_idx` (`SUBJECT_subject_number` ASC, `SUBJECT_subject_name` ASC),
  INDEX `fk_TEACHER_has_SUBJECT_TEACHER1_idx` (`TEACHER_teacher_id` ASC, `TEACHER_PERSON_id` ASC, `TEACHER_PERSON_name` ASC, `TEACHER_PERSON_gender` ASC, `TEACHER_PERSON_age` ASC),
  CONSTRAINT `fk_TEACHER_has_SUBJECT_TEACHER1`
    FOREIGN KEY (`TEACHER_teacher_id` , `TEACHER_PERSON_id` , `TEACHER_PERSON_name` , `TEACHER_PERSON_gender` , `TEACHER_PERSON_age`)
    REFERENCES `mydb`.`TEACHER` (`teacher_id` , `PERSON_id` , `PERSON_name` , `PERSON_gender` , `PERSON_age`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_TEACHER_has_SUBJECT_SUBJECT1`
    FOREIGN KEY (`SUBJECT_subject_number` , `SUBJECT_subject_name`)
    REFERENCES `mydb`.`SUBJECT` (`subject_number` , `subject_name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
