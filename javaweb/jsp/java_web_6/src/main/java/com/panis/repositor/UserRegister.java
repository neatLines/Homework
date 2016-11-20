package com.panis.repositor;

/**
 * Created by fuyipeng on 2016/11/19.
 */
import com.panis.model.UserBean;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class UserRegister {
    private UserBean userBean;
    private Connection con;
    //获得数据库连接。
    public UserRegister() {
        String url="jdbc:mysql://115.159.0.237/"+"javaweb6"+"?user="+"panis"+"&password="+"root";
        try {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            con = DriverManager.getConnection(url);
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
    //设置待注册的用户信息。
    public void setUserBean(UserBean userBean) {
        this.userBean=userBean;
    }
    //进行注册
    public void regist() throws Exception {
        String reg="insert into students(id,link,pwd,roles,uid,username)  values(?,?,?,?,?,?)";
        try {
            PreparedStatement pstmt=con.prepareStatement(reg);
            pstmt.setInt(1,userBean.getId());
            pstmt.setString(2,userBean.getLink());
            pstmt.setString(3,userBean.getPwd());
            pstmt.setString(4,userBean.getRoles());
            pstmt.setString(5,userBean.getUid());
            pstmt.setString(6,userBean.getUsername());
            pstmt.executeUpdate();
        }
        catch(Exception e) {
            e.printStackTrace();
            throw e;
        }
    }

    public List<UserBean> findAll() {
        String reg = "select * from students";
        List<UserBean> list = new ArrayList<UserBean>();
        try {
            PreparedStatement pstmt = con.prepareStatement(reg);
            ResultSet rs = pstmt.executeQuery();
            while (rs.next()) {
                UserBean temp = new UserBean();
                temp.setId(rs.getInt(1));
                temp.setLink(rs.getString(2));
                temp.setPwd(rs.getString(3));
                temp.setRoles(rs.getString(4));
                temp.setUid(rs.getString(5));
                temp.setUsername(rs.getString(6));
                System.out.println(temp.getUsername());
                list.add(temp);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return list;
    }
}