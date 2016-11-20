package com.panis.repository;

import com.panis.model.StudentsEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 * Created by fuyipeng on 2016/11/15.
 */
@Repository
public interface StudentRepository extends JpaRepository<StudentsEntity,Integer> {

}
