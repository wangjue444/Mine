package com.city.hospitalmanagement.factory;

import java.sql.Connection;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

public class ConnectionFactory {
	public static Connection getConnection() throws Exception{
		Connection cn=null;
		try{
			Context ctx=new InitialContext();
			DataSource ds=(DataSource)ctx.lookup("java:comp/env/city");
			cn=ds.getConnection();
			ctx.close();
			
		}
		catch(Exception e){
			throw new Exception("取得数据库连接错误"+e.getMessage());
		}
		
		return cn;
	}

}
