 import java.awt.Choice;
/*     */ import java.awt.Color;
import java.awt.Component;
import java.awt.LayoutManager;
/*     */ import java.awt.event.ActionEvent;
/*     */ import java.awt.event.ActionListener;
/*     */ import java.io.FileInputStream;
/*     */ import java.io.IOException;
/*     */ import java.sql.Connection;
/*     */ import java.sql.DriverManager;
/*     */ import java.sql.PreparedStatement;
/*     */ import java.sql.SQLException;
		import java.util.Date;
/*     */ import java.util.Properties;
/*     */ import java.util.regex.Matcher;
/*     */ import java.util.regex.Pattern;
/*     */ import javax.swing.JButton;
/*     */ import javax.swing.JFrame;
/*     */ import javax.swing.JLabel;
          import javax.swing.JTextArea;
/*     */ import javax.swing.JTextField;
/*     */ 
/*     */ public class TellerResetUtility {
/*     */   private JFrame f;
/*     */   private JLabel h1;
/*     */   private JLabel l1;
/*     */   private JLabel l2;
/*     */   private JLabel l3;
/*     */   private JTextField t1;
/*     */   private JTextField t2;
/*     */   private JTextField t3;
/*  28 */   public String configFile = "\\\\10.0.30.231\\e\\TellerReset\\config.properties"; private JButton b1; private JButton b2; private JButton b3; private Choice dropdown1; private Choice dropdown2; private Choice dropdown3; private Choice dropdown4; private JTextArea l4;
/*     */   
/*     */   public TellerResetUtility() throws IOException {
/*  31 */     this.f = new JFrame();
/*     */     
/*  33 */     JFrame f = new JFrame("TellerResetUtility");
/*     */     
/*  35 */     this.l1 = new JLabel("TELLER NO: ");
/*  36 */     this.l1.setBounds(10, 10, 100, 30);
/*  37 */     f.add(this.l1);
/*     */     
/*  39 */     this.t1 = new JTextField(10);
/*  40 */     this.t1.setBounds(80, 10, 150, 30);
/*  41 */     f.add(this.t1);
/*     */     
/*  43 */     this.dropdown1 = new Choice();
/*  44 */     this.dropdown1.setBounds(230, 10, 50, 30);
/*  45 */     this.dropdown1.add("V3");
/*  46 */     this.dropdown1.add("V4");
/*  47 */     this.dropdown1.add("WD");
/*  48 */     f.add(this.dropdown1);
/*     */     
/*  50 */     this.b1 = new JButton("RESET");
/*  51 */     this.b1.setBounds(295, 10, 100, 30);
/*  52 */     this.b1.addActionListener(new ActionListener() {
/*     */           public void actionPerformed(ActionEvent e) {
/*     */             try {
/*  55 */               TellerResetUtility.this.resetTeller();
/*  56 */             } catch (IOException e1) {
/*     */               
/*  58 */               e1.printStackTrace();
/*     */             } 
/*     */           }
/*     */         });
/*  62 */     f.add(this.b1);
/*     */     
/*  64 */     this.l2 = new JLabel("TELLER NO: ");
/*  65 */     this.l2.setBounds(10, 50, 100, 30);
/*  66 */     f.add(this.l2);
/*     */     
/*  68 */     this.t2 = new JTextField();
/*  69 */     this.t2.setBounds(80, 50, 150, 30);
/*  70 */     f.add(this.t2);
/*     */     
/*  72 */     this.dropdown2 = new Choice();
/*  73 */     this.dropdown2.setBounds(230, 50, 50, 30);
/*  74 */     this.dropdown2.add("V3");
/*  75 */     this.dropdown2.add("V4");
/*  76 */     this.dropdown2.add("WD");
/*  77 */     f.add(this.dropdown2);
/*     */     
/*  79 */     this.b2 = new JButton("SIGNON");
/*  80 */     this.b2.setBounds(295, 50, 100, 30);
/*  81 */     this.b2.addActionListener(new ActionListener() {
/*     */           public void actionPerformed(ActionEvent e) {
/*     */             try {
/*  84 */               TellerResetUtility.this.signOnTeller();
/*  85 */             } catch (IOException e1) {
/*     */               
/*  87 */               e1.printStackTrace();
/*     */             } 
/*     */           }
/*     */         });
/*  91 */     f.add(this.b2);
/*     */ 
/*     */     
/*  94 */     this.l3 = new JLabel("TELLER NO: ");
/*  95 */     this.l3.setBounds(10, 90, 100, 30);
/*  96 */     f.add(this.l3);
/*     */     
/*  98 */     this.t3 = new JTextField();
/*  99 */     this.t3.setBounds(80, 90, 90, 25);
/* 100 */     f.add(this.t3);
/*     */     
/* 102 */     this.dropdown3 = new Choice();
/* 103 */     this.dropdown3.setBounds(174, 90, 50, 50);
/* 104 */     this.dropdown3.add("V3");
/* 105 */     this.dropdown3.add("V4");
/* 106 */     this.dropdown3.add("WD");
/* 107 */     f.add(this.dropdown3);
/*     */     
/* 109 */     this.dropdown4 = new Choice();
/* 110 */     this.dropdown4.setBounds(226, 90, 65, 30);
/* 111 */     this.dropdown4.add("BANCS");
/* 112 */     this.dropdown4.add("EIS");
/* 113 */     f.add(this.dropdown4);
/*     */     
/* 115 */     this.b3 = new JButton("MS-SIGNON");
/* 116 */     this.b3.setBounds(295, 90, 100, 30);
/* 117 */     this.b3.addActionListener(new ActionListener() {
/*     */           public void actionPerformed(ActionEvent e) {
/*     */             try {
/* 120 */               TellerResetUtility.this.signOnMsTeller();
/* 121 */             } catch (Exception e1) {
/*     */               
/* 123 */               e1.printStackTrace();
/*     */             } 
/*     */           }
/*     */         });
/* 127 */     f.add(this.b3);
/*     */ 
/*     */     
/* 130 */     this.l4 = new JTextArea(10, 20);
/* 131 */     this.l4.setLineWrap(true);
/* 132 */     this.l4.setWrapStyleWord(true);
/* 133 */     this.l4.setBounds(10, 130, 380, 30);
/* 134 */     this.l4.setEditable(false);
/* 135 */     this.l4.setBackground(new Color(240, 240, 233));
/* 136 */     f.add(this.l4);
/*     */     
/* 138 */     f.setSize(420, 200);
/* 139 */     f.setLayout((LayoutManager)null);
/* 140 */     f.setLocationRelativeTo((Component)null);
/* 141 */     f.setVisible(true);
/* 142 */     f.setResizable(false);
/* 143 */     f.setDefaultCloseOperation(3);
/*     */   }
/*     */   
/*     */   public void resetTeller() throws IOException {
/* 147 */     Properties prop = new Properties();
/* 148 */     FileInputStream ip = null;
/*     */     
/*     */     try {
/* 151 */       ip = new FileInputStream(this.configFile);
/* 152 */     } catch (Exception e) {
/* 153 */       System.out.println(e.getMessage());
/*     */     } 
/*     */     
/* 156 */     prop.load(ip);
/*     */     
/* 158 */     String tellerid = this.t1.getText();
/* 159 */     String region = this.dropdown1.getSelectedItem();
/* 160 */     Connection connection = null;
/* 161 */     PreparedStatement preparedStatement = null;
/*     */     
/* 163 */     Pattern letter = Pattern.compile("[a-zA-z]");
/* 164 */     Pattern special = Pattern.compile("[!@#$%&*()_,.:;+=|<>?{}\\[\\]~-]");
/*     */     
/* 166 */     Matcher hasLetter = letter.matcher(tellerid);
/* 167 */     Matcher hasSpecial = special.matcher(tellerid);
/*     */     
/* 169 */     boolean b1 = hasLetter.find();
/* 170 */     boolean b2 = hasSpecial.find();
/*     */     
/* 172 */     if (tellerid.length() > 7 || tellerid.isEmpty() || b1 || b2) {
/* 173 */       this.l4.setText("Invalid teller.");
/* 174 */       this.l4.setForeground(Color.RED);
/*     */     } else {
/*     */       try {
/*     */         String str1;
/* 178 */         switch ((str1 = region).hashCode()) { case 2717: if (!str1.equals("V3"))
/*     */               break; 
/* 180 */             connection = DriverManager.getConnection(prop.getProperty("db.v3.url"), 
/* 181 */                 prop.getProperty("db.v3.user"), prop.getProperty("db.v3.password")); break;
/*     */           case 2718:
/*     */             if (!str1.equals("V4"))
/* 184 */               break;  connection = DriverManager.getConnection(prop.getProperty("db.v4.url"), 
/* 185 */                 prop.getProperty("db.v4.user"), prop.getProperty("db.v4.password")); break;
/*     */           case 2765:
/*     */             if (!str1.equals("WD"))
/* 188 */               break;  connection = DriverManager.getConnection(prop.getProperty("db.wd.url"), 
/* 189 */                 prop.getProperty("db.wd.user"), prop.getProperty("db.wd.password"));
/*     */             break; }
/*     */ 
/*     */ 
/*     */         
/* 194 */         String updateQuery = "update telm set SIGNON_FLAG = 'N', CHANGE_PWORD_DATE = '72966', SIGN_ON_DATE = '00000000',TELLER_PWORD_RETRY = '0', STAT = '00', TELLER_PWORD = chr(39)||chr(39)||chr(63)||chr(64)||chr(32)||chr(64)||chr(67)||chr(32)||chr(36)||chr(51) where soc_no = '003' and TELLER_NO = ?";
/*     */ 
/*     */         
/* 197 */         preparedStatement = connection.prepareStatement(updateQuery);
/*     */ 
/*     */         
/* 200 */         int tellerid1 = Integer.parseInt(tellerid);
/* 201 */         String tellerid2 = String.format("%016d", new Object[] { Integer.valueOf(tellerid1) });
/* 202 */         preparedStatement.setString(1, tellerid2);
/*     */ 
/*     */         
/* 205 */         int rowsAffected = preparedStatement.executeUpdate();
/*     */         
/* 207 */         this.l4.setText("TellerID " + tellerid2 + " : resetted in " + region + " with password as 1.");
/* 208 */         this.l4.setForeground(new Color(0, 190, 93));
/* 209 */       } catch (SQLException e) {
/* 210 */         this.l4.setText(e.getMessage());
/* 211 */         this.l4.setForeground(Color.RED);
/*     */       } finally {
/*     */         
/*     */         try {
/* 215 */           if (preparedStatement != null) {
/* 216 */             preparedStatement.close();
/*     */           }
/* 218 */         } catch (SQLException e) {
/* 219 */           e.printStackTrace();
/*     */         } 
/*     */       } 
/*     */     } 
/*     */   }
/*     */   
/*     */   public void signOnTeller() throws IOException {
/* 226 */     Properties prop = new Properties();
/* 227 */     FileInputStream ip = null;
/*     */     
/*     */     try {
/* 230 */       ip = new FileInputStream(this.configFile);
/* 231 */     } catch (Exception e) {
/* 232 */       System.out.println(e.getMessage());
/*     */     } 
/* 234 */     prop.load(ip);
/* 235 */     String tellerid = this.t2.getText();
/* 236 */     String region = this.dropdown2.getSelectedItem();
/* 237 */     Connection connection = null;
/* 238 */     PreparedStatement preparedStatement = null;
/*     */     
/* 240 */     Pattern letter = Pattern.compile("[a-zA-z]");
/* 241 */     Pattern special = Pattern.compile("[!@#$%&*()_,.:;+=|<>?{}\\[\\]~-]");
/*     */     
/* 243 */     Matcher hasLetter = letter.matcher(tellerid);
/* 244 */     Matcher hasSpecial = special.matcher(tellerid);
/*     */     
/* 246 */     boolean b1 = hasLetter.find();
/* 247 */     boolean b2 = hasSpecial.find();
/*     */     
/* 249 */     if (tellerid.length() > 7 || tellerid.isEmpty() || b1 || b2) {
/* 250 */       this.l4.setText("Invalid teller.");
/* 251 */       this.l4.setForeground(Color.RED);
/*     */     } else {
/*     */       try {
/*     */         String str1;
/* 255 */         switch ((str1 = region).hashCode()) { case 2717: if (!str1.equals("V3"))
/*     */               break; 
/* 257 */             connection = DriverManager.getConnection(prop.getProperty("db.v3.url"), 
/* 258 */                 prop.getProperty("db.v3.user"), prop.getProperty("db.v3.password")); break;
/*     */           case 2718:
/*     */             if (!str1.equals("V4"))
/* 261 */               break;  connection = DriverManager.getConnection(prop.getProperty("db.v4.url"), 
/* 262 */                 prop.getProperty("db.v4.user"), prop.getProperty("db.v4.password")); break;
/*     */           case 2765:
/*     */             if (!str1.equals("WD"))
/* 265 */               break;  connection = DriverManager.getConnection(prop.getProperty("db.wd.url"), 
/* 266 */                 prop.getProperty("db.wd.user"), prop.getProperty("db.wd.password"));
/*     */             break; }
/*     */ 
/*     */ 
/*     */         
/* 271 */         String updateQuery = "update telm set SIGNON_FLAG = 'N' where soc_no = '003' and TELLER_NO = ?";
/*     */ 
/*     */         
/* 274 */         preparedStatement = connection.prepareStatement(updateQuery);
/*     */ 
/*     */         
/* 277 */         int tellerid1 = Integer.parseInt(tellerid);
/* 278 */         String tellerid2 = String.format("%016d", new Object[] { Integer.valueOf(tellerid1) });
/* 279 */         preparedStatement.setString(1, tellerid2);
/*     */ 
/*     */         
/* 282 */         int rowsAffected = preparedStatement.executeUpdate();
/* 283 */         this.l4.setText("TellerID " + tellerid2 + " : signed on in " + region);
/* 284 */         this.l4.setForeground(new Color(0, 190, 93));
/* 285 */       } catch (SQLException e) {
/* 286 */         this.l4.setText(e.getMessage());
/* 287 */         this.l4.setForeground(Color.RED);
/*     */       } finally {
/*     */ 
/*     */         
/*     */         try {
/*     */           
/* 293 */           if (preparedStatement != null) {
/* 294 */             preparedStatement.close();
/*     */           }
/* 296 */         } catch (SQLException e) {
/* 297 */           e.printStackTrace();
/*     */         } 
/*     */       } 
/*     */     } 
/*     */   }
/*     */   
/*     */   public void signOnMsTeller() throws Exception {
/* 304 */     Properties prop = new Properties();
/* 305 */     FileInputStream ip = null;
/*     */     
/*     */     try {
/* 308 */       ip = new FileInputStream(this.configFile);
/* 309 */     } catch (Exception e) {
/* 310 */       System.out.println(e.getMessage());
/*     */     } 
/* 312 */     prop.load(ip);
/* 313 */     String tellerid = this.t3.getText();
/* 314 */     String region = this.dropdown3.getSelectedItem();
/* 315 */     String regionType = this.dropdown4.getSelectedItem();
/* 316 */     Connection connection = null;
/* 317 */     PreparedStatement preparedStatement = null;
/*     */     
/* 319 */     Pattern letter = Pattern.compile("[a-zA-z]");
/* 320 */     Pattern special = Pattern.compile("[!@#$%&*()_,.:;+=|<>?{}\\[\\]~-]");
/*     */     
/* 322 */     Matcher hasLetter = letter.matcher(tellerid);
/* 323 */     Matcher hasSpecial = special.matcher(tellerid);
/*     */     
/* 325 */     boolean b1 = hasLetter.find();
/* 326 */     boolean b2 = hasSpecial.find();
/*     */     
/* 328 */     if (tellerid.length() > 7 || tellerid.isEmpty() || b1 || b2) {
/* 329 */       this.l4.setText("Invalid teller.");
/* 330 */       this.l4.setForeground(Color.RED);
/*     */     } else {
/*     */       try {
/*     */         String str1;
/* 334 */         switch ((str1 = region).hashCode()) { case 2717: if (!str1.equals("V3"))
/*     */               break; 
/* 336 */             connection = DriverManager.getConnection(prop.getProperty("db.v3.url"), 
/* 337 */                 prop.getProperty("db.v3.user"), prop.getProperty("db.v3.password")); break;
/*     */           case 2718:
/*     */             if (!str1.equals("V4"))
/* 340 */               break;  connection = DriverManager.getConnection(prop.getProperty("db.v4.url"), 
/* 341 */                 prop.getProperty("db.v4.user"), prop.getProperty("db.v4.password")); break;
/*     */           case 2765:
/*     */             if (!str1.equals("WD"))
/* 344 */               break;  connection = DriverManager.getConnection(prop.getProperty("db.wd.url"), 
/* 345 */                 prop.getProperty("db.wd.user"), prop.getProperty("db.wd.password"));
/*     */             break; }
/*     */ 
/*     */ 
/*     */         
/* 350 */         String updateQuery = "";
/* 351 */         Date date = new Date();
/* 352 */         String todays_date = String.valueOf(DateConverter.toBinary(date));
/* 353 */         int tellerid1 = Integer.parseInt(tellerid);
/* 354 */         String tellerid2 = String.format("%016d", new Object[] { Integer.valueOf(tellerid1) }); String str2;
/* 355 */         switch ((str2 = regionType).hashCode()) { case 68655: if (!str2.equals("EIS"))
/*     */               break; 
/* 357 */             updateQuery = "update telm set SIGNON_FLAG = 'Y' where soc_no = '003' and TELLER_NO = ?";
/* 358 */             preparedStatement = connection.prepareStatement(updateQuery);
/* 359 */             preparedStatement.setString(1, tellerid2); break;
/*     */           case 62965919:
/*     */             if (!str2.equals("BANCS"))
/* 362 */               break;  updateQuery = "update telm set SIGNON_FLAG = 'Y', sign_on_date_bin = ? where soc_no = '003' and TELLER_NO = ?";
/* 363 */             preparedStatement = connection.prepareStatement(updateQuery);
/* 364 */             preparedStatement.setString(1, todays_date);
/* 365 */             preparedStatement.setString(2, tellerid2);
/*     */             break; }
/*     */ 
/*     */ 
/*     */         
/* 370 */         int rowsAffected = preparedStatement.executeUpdate();
/* 371 */         this.l4.setText("TellerID " + tellerid2 + " : signed on in " + region + " for " + regionType);
/* 372 */         this.l4.setForeground(new Color(0, 190, 93));
/* 373 */       } catch (SQLException e) {
/* 374 */         this.l4.setText(e.getMessage());
/* 375 */         this.l4.setForeground(Color.RED);
/*     */       } finally {
/*     */ 
/*     */         
/*     */         try {
/*     */           
/* 381 */           if (preparedStatement != null) {
/* 382 */             preparedStatement.close();
/*     */           }
/* 384 */         } catch (SQLException e) {
/* 385 */           e.printStackTrace();
/*     */         } 
/*     */       } 
/*     */     } 
/*     */   }
/*     */   
/*     */   public static void main(String[] args) throws IOException {}
/*     */ }
