package com.example.myapplication

import android.annotation.SuppressLint
import android.os.AsyncTask
import android.os.Bundle
import android.provider.ContactsContract.CommonDataKinds.Website.URL
import android.widget.TextView
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.sp
import com.example.myapplication.ui.theme.MyApplicationTheme
import kotlinx.coroutines.DelicateCoroutinesApi
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import org.json.JSONObject
import java.net.URL


class MainActivity : ComponentActivity() {
    private val apiKey = "edec4e78ee96360a47d5056d41d61daf"
    private val city = "Kolomna"

    /*@OptIn(DelicateCoroutinesApi::class)
    @SuppressLint("CoroutineCreationDuringComposition")*/
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.main_activity)

        WeatherTask().execute()
    }

    inner class WeatherTask() : AsyncTask<String, Void, String>() {

        override fun doInBackground(vararg params: String?): String? {
            var response: String?
            try {
                response = URL("https://api.openweathermap.org/data/2.5/weather?q=$city&units=metric&appid=$apiKey")
                    .readText(Charsets.UTF_8)
            }
            catch (e: Exception) {
                response = null
            }

            return  response
        }

        override fun onPostExecute(result: String?) {
            super.onPostExecute(result)
            try {
                var jsonObj = JSONObject(result)
                val main = jsonObj.getJSONObject("main")
                val sys = jsonObj.getJSONObject("sys")

                val temp = main.getString("temp")
                val address = jsonObj.getString("name") + ", " + sys.getString("country")
                val feelsLike = main.getString("feels_like")

                findViewById<TextView>(R.id.location).text = address
                findViewById<TextView>(R.id.temperature).text = temp
                findViewById<TextView>(R.id.feelsLike).text = feelsLike
            }
            catch (e: Exception) {

            }
        }
    }
}