package com.review;

import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.expr.MethodCallExpr;
import java.util.*;

public class NullPointerRule {

    public List<ReviewResult> apply(CompilationUnit cu) {
        List<ReviewResult> results = new ArrayList<>();

        cu.findAll(MethodCallExpr.class).forEach(expr -> {
            if ("length".equals(expr.getNameAsString())) {
                expr.getBegin().ifPresent(pos ->
                    results.add(new ReviewResult(
                        pos.line,
                        "ERROR",
                        "Possible NullPointerException: length() call"
                    ))
                );
            }
        });

        return results;
    }
}
