package com.example.myapplication

import android.os.Bundle
import android.widget.TextView
import androidx.activity.ComponentActivity
import java.math.BigDecimal
import java.math.RoundingMode
import android.widget.Button

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.main_activity)

        findViewById<Button>(R.id.plus).setOnClickListener {
            add()
        }
        findViewById<Button>(R.id.minus).setOnClickListener {
            subtract()
        }
        findViewById<Button>(R.id.multiply).setOnClickListener {
            multiply()
        }
        findViewById<Button>(R.id.divide).setOnClickListener {
            divide()
        }
    }

    fun add(){
        var inputdata1=findViewById<TextView>(R.id.input1).text.toString().trim().toBigDecimal()
        var inputdata2=findViewById<TextView>(R.id.input2).text.toString().trim().toBigDecimal()
        findViewById<TextView>(R.id.result).text=inputdata1.add(inputdata2).toString()
    }

    fun subtract(){
        var inputdata1=findViewById<TextView>(R.id.input1).text.toString().trim().toBigDecimal()
        var inputdata2=findViewById<TextView>(R.id.input2).text.toString().trim().toBigDecimal()
        findViewById<TextView>(R.id.result).text=inputdata1.subtract(inputdata2).toString()
    }

    fun multiply(){
        var inputdata1=findViewById<TextView>(R.id.input1).text.toString().trim().toBigDecimal()
        var inputdata2=findViewById<TextView>(R.id.input2).text.toString().trim().toBigDecimal()
        findViewById<TextView>(R.id.result).text=inputdata1.multiply(inputdata2).toString()
    }


    fun divide(){
        var inputdata1=findViewById<TextView>(R.id.input1).text.toString().trim().toBigDecimal()
        var inputdata2=findViewById<TextView>(R.id.input2).text.toString().trim().toBigDecimal()

        if(inputdata2.compareTo(BigDecimal.ZERO)==0)
        {
            findViewById<TextView>(R.id.input1).error="invalid input"
        }
        else
        {
            findViewById<TextView>(R.id.result).text = inputdata1.divide(inputdata2, 2, RoundingMode.HALF_UP).toString();
        }

    }
}