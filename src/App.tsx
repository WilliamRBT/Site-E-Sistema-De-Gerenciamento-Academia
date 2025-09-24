import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Header from './components/Header';
import Hero from './components/Hero';
import Features from './components/Features';
import Pricing from './components/Pricing';
import Testimonials from './components/Testimonials';
import CallToAction from './components/CallToAction';
import Footer from './components/Footer';
import ContactPage from './pages/ContactPage';
import PlanDetailsPage from './pages/PlanDetailsPage';

// Layout component for pages that share Header and Footer
const MainLayout: React.FC<{ children: React.ReactNode }> = ({ children }) => (
  <div className="bg-[#121212] text-gray-200 min-h-screen">
    <Header />
    <main>{children}</main>
    <Footer />
  </div>
);

const App: React.FC = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={
          <MainLayout>
            <Hero />
            <Features />
            <Pricing />
            <Testimonials />
            <CallToAction />
          </MainLayout>
        } />
        <Route path="/contato" element={
          <MainLayout>
            <ContactPage />
          </MainLayout>
        } />
        <Route path="/planos/:planName" element={
          <MainLayout>
            <PlanDetailsPage />
          </MainLayout>
        } />
      </Routes>
    </Router>
  );
};

export default App;