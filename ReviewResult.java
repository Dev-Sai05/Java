package com.review;

public class ReviewResult {
    public int line;
    public String severity;
    public String message;

    public ReviewResult(int line, String severity, String message) {
        this.line = line;
        this.severity = severity;
        this.message = message;
    }
}
