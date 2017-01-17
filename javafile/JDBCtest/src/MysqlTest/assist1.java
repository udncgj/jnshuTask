package MysqlTest;
import java.sql.*;
public class assist1 {
	public static final String url="jdbc:mysql://localhost/test";//jdbc:mysql://localhost/root
	public static final String name="com.mysql.jdbc.Driver";
	public static final String user="root";
	public static final String password=null;
	public static void main(String args[]){
		Connection conn=null;
		PreparedStatement pst=null;
		try{
			Class.forName(name);
			conn=DriverManager.getConnection(url, user, password);
			System.out.println(conn);
			conn.close();
//			pst.close();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
}