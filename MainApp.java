package com.review;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.List;

import com.github.javaparser.JavaParser;
import com.github.javaparser.ast.CompilationUnit;

public class MainApp {

    public static void main(String[] args) {
        SwingUtilities.invokeLater(MainApp::new);
    }

    public MainApp() {
        JFrame frame = new JFrame("Java Code Review Tool (Swing)");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTextArea codeArea = new JTextArea();
        JScrollPane codeScroll = new JScrollPane(codeArea);

        JButton reviewBtn = new JButton("Review Code");

        String[] cols = {"Line", "Severity", "Comment"};
        DefaultTableModel model = new DefaultTableModel(cols, 0);
        JTable table = new JTable(model);
        JScrollPane tableScroll = new JScrollPane(table);

        reviewBtn.addActionListener(e -> {
            model.setRowCount(0);
            try {
                CompilationUnit cu = JavaParser.parse(codeArea.getText());
                List<ReviewResult> results = new NullPointerRule().apply(cu);
                for (ReviewResult r : results) {
                    model.addRow(new Object[]{r.line, r.severity, r.message});
                }
            } catch (Exception ex) {
                model.addRow(new Object[]{0, "ERROR", "Invalid Java syntax"});
            }
        });

        JSplitPane split = new JSplitPane(JSplitPane.VERTICAL_SPLIT, codeScroll, tableScroll);
        split.setDividerLocation(300);

        frame.add(split, BorderLayout.CENTER);
        frame.add(reviewBtn, BorderLayout.SOUTH);
        frame.setVisible(true);
    }
}
