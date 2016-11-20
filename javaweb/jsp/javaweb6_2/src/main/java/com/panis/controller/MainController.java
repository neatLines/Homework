package com.panis.controller;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;

import com.panis.model.StudentsEntity;
import com.panis.repository.StudentRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import java.net.HttpCookie;
import java.util.List;

/**
 * Created by fuyipeng on 2016/11/15.
 */
@Controller
public class MainController {
    @Autowired
    StudentRepository studentRepository;

    @RequestMapping(value = "/", method = RequestMethod.GET)
    public String index(ModelMap modelMap) {
        List<StudentsEntity> students = studentRepository.findAll();
        modelMap.addAttribute(students);
        return "list";
    }

    @RequestMapping(value = "/new", method = RequestMethod.GET)
    public String newS() {
        return "new";
    }

    @RequestMapping(value = "/newConfirm", method = RequestMethod.POST)
    public String addStudent(@ModelAttribute("student") StudentsEntity studentsEntity){
        List<StudentsEntity> students = studentRepository.findAll();
        studentsEntity.setId(students.size()+1);
        System.out.println(studentsEntity.getUsername());
        System.out.println(studentsEntity.getId());
        studentRepository.saveAndFlush(studentsEntity);
        return "redirect:/";
    }
}
